# https://www.spoj.com/problems/PT07Y/
n,m = map(int,input().split())
adj = [[] for x in range(n)]
visited = [0 for x in range(n)]
def dfs(node):
    visited[node]=1
    cycle = False
    for i in adj[node]:
        if not visited[i]: cycle|=dfs(i)
        else: return True
    visited[node] = 2
    return cycle

for x in range(m):
    a,b = map(int,input().split())
    adj[a-1].append(b-1)
cycle = dfs(0)
allVisited = all([x for x in visited])
if cycle or not allVisited:print("NO")
else: print("YES")
