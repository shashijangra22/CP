# https://www.spoj.com/problems/CRDS/
import sys
reader = (s.rstrip() for s in sys.stdin)
input = reader.__next__
# do magic here
MOD = 1000007
def solve(n):
    return (2*n)%MOD + ((((n)*(n-1))//2) * 3)%MOD

t = int(input())
for _ in range(t):
    n = int(input())
    print(solve(n)%MOD)