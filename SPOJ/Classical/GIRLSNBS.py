# https://www.spoj.com/problems/GIRLSNBS/
import sys
reader = (s.rstrip() for s in sys.stdin)
input = reader.__next__
# do magic here


def solve(g, b):
    if not g or not b:
        return max(g,b)
    if abs(g-b) <= 1:
        return 1
    num = abs(g-b) - 1
    den = min(g,b) + 1
    return 1 + (num + den - 1)//den
    

while 1:
    g, b = map(int, input().split())
    if g==b and g==-1:
        break
    print(solve(g, b))
