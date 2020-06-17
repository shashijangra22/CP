# https://www.spoj.com/problems/BUGLIFE/
from math import pi
import sys
reader = (s.rstrip() for s in sys.stdin)
input = reader.__next__
sys.setrecursionlimit(100000)
# do magic here

color = []


def dfs(node, clr):
    color[node] = clr
    flag = True
    for x in adj[node]:
        if color[x] == -1:
            flag = flag and dfs(x, clr ^ 1)
        if color[x]==color[node]:
            flag = False
            break
    return flag


t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    adj = [[] for x in range(n+1)]
    color = [-1 for x in range(n+1)]
    for x in range(m):
        a, b = map(int, input().split())
        adj[a].append(b)
        adj[b].append(a)
    ans = True
    for x in range(1, n+1):
        if color[x] == -1:
            ans = ans and dfs(x, 0)
    print("Scenario #{}:".format(_+1))
    if ans:
        print("No suspicious bugs found!")
    else:
        print("Suspicious bugs found!")
