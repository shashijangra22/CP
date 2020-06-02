# https://www.spoj.com/problems/STAMPS/
import bisect
t = int(input())
for _ in range(t):
    print("Scenario #{}:".format(_+1))
    val,n = map(int,input().split())
    arr = sorted([int(x) for x in input().split()],reverse=True)
    for x in range(1,n):
        arr[x]+=arr[x-1]
    c = bisect.bisect_left(arr,val)+1
    if c>n:
        print("impossible")
    else:
        print(c)
    print("")
