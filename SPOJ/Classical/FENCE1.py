# https://www.spoj.com/problems/FENCE1/
import sys
from math import pi
reader = (s.rstrip() for s in sys.stdin)
input = reader.__next__
# do magic here


def solve(l):
    return l**2 / (2*pi)

while 1:
    l = int(input())
    if not l:
        break
    ans = solve(l)
    print("{:.2f}".format(ans))
