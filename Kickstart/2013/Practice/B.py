# https://code.google.com/codejam/contest/dashboard?c=2933486#s=p1
from math import asin,pi
t=int(input())
for _ in range(t):
	ans=0
	v,d=map(int,input().split())
	d=d*9.8
	v=v**2
	theta=round(asin(round(d/v,10))*(180/pi)/2,7)
	print("Case #"+str(_+1)+":",theta)
