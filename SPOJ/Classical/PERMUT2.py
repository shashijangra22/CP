# https://www.spoj.com/problems/PERMUT2/
import sys
reader = (s.rstrip() for s in sys.stdin)
input = reader.__next__
# do magic here
while True:
    n = int(input())
    if not n:
        break
    perm = [int(x)-1 for x in input().split()]
    pos = [0 for x in range(n)]
    for ind,val in enumerate(perm):
        pos[val] = ind
    flag = True
    for ind in range(n):
        if pos[ind]!=perm[ind]:
            flag = False
            break
    print("ambiguous" if flag else "not ambiguous")