# https://code.google.com/codejam/contest/2924486/dashboard#s=p1
def f1(n):
	if n==1:
		return 1,1
	p,q=f1(n//2)
	if n&1:
		return p+q,q
	return p,p+q

def f2(p,q):
	if p==q:
		return 1
	if p>q: #right child
		return f2(p-q,q)*2 + 1
	return f2(p,q-p)*2 # left child

t=int(input())
for _ in range(t):
	inp=[int(x) for x in input().split()]
	print("Case #{}: ".format(_+1),end=' ')
	if inp[0]==1:
		p,q=f1(inp[1]) #find Nth
		print(p,q)
	else:
		n=f2(inp[1],inp[2]) # find N
		print(n)