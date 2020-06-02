# https://www.spoj.com/problems/GNYR09F/
dp=[]

for x in range(101):
	temp=[]
	for y in range(101):
		temp2=[]
		for z in range(2):
			temp2.append('#')
		temp.append(temp2)
	dp.append(temp)

def fun(n,k,bit):
	if dp[n][k][bit]!='#':
		return dp[n][k][bit]
	if n==1:
		if k==0:
			dp[n][k][bit]=1
		else:
			dp[n][k][bit]=0
		return dp[n][k][bit]
	if bit==0:
		dp[n][k][bit]=fun(n-1,k,0)+fun(n-1,k,1)
	else:
		dp[n][k][bit]=fun(n-1,k,0)+fun(n-1,k-1,1)
	return dp[n][k][bit]

t=int(input())
for _ in range(t):
	c,n,k=[int(x) for x in input().split(' ')]
	print(c,fun(n,k,0)+fun(n,k,1))