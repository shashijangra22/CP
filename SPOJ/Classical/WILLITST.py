# https://www.spoj.com/problems/WILLITST/
n = int(input())
if not n or n == (n & -n):
    print("TAK")
else:
    print("NIE")