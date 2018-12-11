# https://www.spoj.com/problems/FCTRL2/
facts=[x for x in range(101)]
for i in range(2,101):
	facts[i]=facts[i]*facts[i-1]
# print(facts)
t=int(input())
while t:
	n=int(input())
	print(facts[n])
	t-=1