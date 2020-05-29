# https://www.spoj.com/problems/ZSUM/
m = 10000007


def modPow(a, b, m):
    a %= m
    res = 1
    while b:
        if b & 1:
            res = (res*a) % m
        a = (a*a) % m
        b >>= 1
    return res % m


def solve(n, k):
    return modPow(n, k, m) + modPow(n, n, m) + 2 * (modPow(n-1, k, m) + modPow(n-1, n-1, m))


while True:
    n, k = map(int, input().split())
    if not n and not k:
        break
    print(solve(n, k) % m)
