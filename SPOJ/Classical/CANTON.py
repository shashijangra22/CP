# https://www.spoj.com/problems/CANTON/
import sys,bisect
reader = (s.rstrip() for s in sys.stdin)
input = reader.__next__
# do magic here
dp = [0, 1]
i = 2
while dp[-1] < int(1e8):
    dp.append(i+dp[-1])
    i+=1
t = int(input())
for _ in range(t):
    n = int(input())
    d = bisect.bisect_left(dp,n)
    termsLeft = dp[d-1]
    pos = n-dp[d-1]
    pos = pos if not d&1 else d-pos+1
    print("TERM {} IS {}/{}".format(n,pos,d-pos+1))