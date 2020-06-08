# https://www.spoj.com/problems/AP2/
import sys
reader = (s.rstrip() for s in sys.stdin)
input = reader.__next__
sys.setrecursionlimit(1000000)
# do magic here
t = int(input())
for _ in range(t):
    third, thirdLast, SUM = map(int, input().split())
    N = (2*SUM)//(third + thirdLast)
    D = (thirdLast - third)//(N - 5)
    first = third - 2 * D
    print(N)
    arr = [str(first + (X-1) * D) for X in range(1, N+1)]
    print(" ".join(arr))
