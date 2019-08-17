# https://www.spoj.com/problems/EIGHTS/
for _ in range(int(input())):
	x=int(input())
	temp=(x//2)+(x&1)
	if (x&1):
		print((1+(temp-1)*5)*100+92)
	else:
		print((4+(temp-1)*5)*100+42)