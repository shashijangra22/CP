from bs4 import BeautifulSoup as bs
import requests
import argparse
import os

ap = argparse.ArgumentParser()
ap.add_argument(
    "-f", "--file", help="Enter path of file to be tested", required=True)
args = vars(ap.parse_args())

def getUrlFromFile():
    # Improved to find the URL anywhere in the first few lines, 
    # even if preceded by comment characters like // or #
    with open(args["file"], "r") as f:
        for line in f:
            pos = line.find("http")
            if pos != -1:
                # Extract URL and drop any trailing comments or spaces
                return line[pos:].split()[0]
    return None

args["url"] = getUrlFromFile()
if not args["url"]:
    print("[Error]: Could not find a valid URL in the source file.")
    exit()

def getTests(dirName):
    inputs, outputs = [], []
    
    # Added a User-Agent to bypass Codeforces' basic bot protection (403 Forbidden)
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36'
    }
    res = requests.get(args["url"], headers=headers)
    if res.status_code != 200:
        print(f"[Error]: Failed to fetch page. Status code: {res.status_code}")
        return
        
    soup = bs(res.text, 'html.parser')

    def scrapeText(div):
        pre = div.find('pre')
        if not pre: return ""
        
        # Codeforces now uses <br> or <div> for line breaks. 
        # Replace <br> with newlines explicitly.
        for br in pre.find_all('br'):
            br.replace_with('\n')
            
        # get_text with a newline separator handles their block elements cleanly
        return pre.get_text(separator='\n').strip()

    inputDiv = soup.find_all('div', {"class": "input"})
    outputDiv = soup.find_all('div', {"class": "output"})
    
    if not inputDiv:
        print("[Warning]: No test cases found. Check the URL or CF bot protection.")

    for x in range(len(inputDiv)):
        inputs.append(scrapeText(inputDiv[x]))
        outputs.append(scrapeText(outputDiv[x]))
        
    for ind in range(len(inputs)):
        # Replaced os.chdir() with direct pathing to prevent directory state bugs
        with open(os.path.join(dirName, f"test-{ind+1}.in"), "w") as f:
            f.write(inputs[ind])
        with open(os.path.join(dirName, f"test-{ind+1}.out"), "w") as f:
            f.write(outputs[ind])

try:
    # Cleaner directory name generation, stripping trailing slashes
    dirName = args["url"].rstrip('/').split('/')[-1] + "_test"
except Exception:
    print("Invalid URL!")
    exit()

if os.path.exists(dirName):
    print(f"Directory '{dirName}' already exists! Reading from Directory...")
else:
    print("Fetching sample tests from server...")
    os.mkdir(dirName)
    getTests(dirName)

# Fixed test case sorting so test-10 runs after test-9, not after test-1
tests = [file.split('.')[0] for file in os.listdir(dirName) if file.endswith('.in')]
tests.sort(key=lambda x: int(x.split('-')[1]))

ext = os.path.splitext(args["file"])[1]

def getCommand(ext, test):
    if ext == ".cpp":
        return f"./a.out < {dirName}/{test}.in > {dirName}/my{test}.out"
    elif ext == ".py":
        return f"python3 {args['file']} < {dirName}/{test}.in > {dirName}/my{test}.out"
    return ""

if ext == ".cpp":
    command = f"g++ {args['file']} -std=c++17"
    print("Compiling source code...")
    # Added error check to prevent running outdated binaries if compilation fails
    if os.system(command) != 0:
        print("[Error]: Compilation failed!")
        exit()
elif ext == ".py":
    pass
else:
    print("[Error]: Language not supported!")
    exit()

for test in tests:
    print(f"\nRunning {test} => ", end="")
    command = getCommand(ext, test)
    os.system(command)
    
    with open(f"{dirName}/{test}.out", "r") as expectedFile, \
         open(f"{dirName}/my{test}.out", "r") as myresultFile, \
         open(f"{dirName}/{test}.in", "r") as inputFile:
             
        expected = expectedFile.read().strip()
        myresult = myresultFile.read().strip()
        
        if expected == myresult:
            print("Passed!")
        else:
            print("Failed !!!")
            print("\n--- Input ---")
            print(inputFile.read().strip())
            print("\n--- Expected Output ---")
            print(expected)
            print("\n--- My Output ---")
            print(myresult)