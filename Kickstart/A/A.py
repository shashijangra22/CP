# https://code.google.com/codejam/contest/2924486/dashboard#s=p0

def makeCounter(string):
	l=len(string)
	ans=[[string[0],1]]
	for x in range(1,l):
		if string[x]==string[x-1]:
			ans[-1][1]+=1
		else:
			ans.append([string[x],1])
	return ans

inWords={
	'0':"zero",
	'1':"one",
	'2':"two",
	'3':"three",
	'4':"four",
	'5':"five",
	'6':"six",
	'7':"seven",
	'8':"eight",
	'9':"nine"
}

freq={
	1:"",
	2:"double",
	3:"triple",
	4:"quadruple",
	5:"quintuple",
	6:"sextuple",
	7:"septuple",
	8:"octuple",
	9:"nonuple",
	10:"decuple"
}

t=int(input())
for _ in range(t):
	string,form=map(str,input().split())
	form=form.split('-')
	begin=0
	ans=[]
	for x in form:
		limit=begin+int(x)
		tokens=makeCounter(string[begin:limit])
		for token in tokens:
			if token[1] in freq:
				ans.append(freq[token[1]])
				ans.append(inWords[token[0]])
			else:
				for c in range(int(token[1])):
					ans.append(inWords[token[0]])
		begin=limit
	print("Case #{}: {}".format(_+1,' '.join(filter(None,ans))))