# https://www.spoj.com/problems/HANGOVER/

def solve(n):
    i = 2
    while n > 0.00:
        n-=(1/i)
        i+=1
    return i-2

while True:
    n = float(input())
    if n==0.0:
        break
    print("{} card(s)".format(solve(n)))