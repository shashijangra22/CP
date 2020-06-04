# https://www.spoj.com/problems/ABSYS/
import sys
reader = (s.rstrip() for s in sys.stdin)
input = reader.__next__
# do magic here
t = int(input())
for _ in range(t):
    blank = input()
    INPUT = input().replace("= ","").replace("+ ","").split()
    if 'm' in INPUT[0]:
        INPUT[0] = abs(int(INPUT[1])-int(INPUT[2]))
    elif 'm' in INPUT[1]:
        INPUT[1] = abs(int(INPUT[0])-int(INPUT[2]))
    else:
        INPUT[2] = abs(int(INPUT[0])+int(INPUT[1]))
    print("{} + {} = {}".format(INPUT[0],INPUT[1],INPUT[2]))
