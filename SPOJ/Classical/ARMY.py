# https://www.spoj.com/problems/ARMY/
import sys
reader = (s.rstrip() for s in sys.stdin)
input = reader.__next__
# do magic here
t = int(input())
for _ in range(t):
    blank = input()
    n,m = map(int,input().split())
    God = max([int(x) for x in input().split()])
    MechaGod = max([int(x) for x in input().split()])
    print("MechaGodzilla" if MechaGod > God else "Godzilla")