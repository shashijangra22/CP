# https://code.google.com/codejam/contest/dashboard?c=2933486#s=p2
t=int(input())
for _ in range(t):
	ans=0
	n=int(input())
	last=" "
	for x in range(n):
		string=input()
		if string < last:
			ans+=1
		else:
			last= string
	print("Case #{}: {}".format(_+1,ans))
