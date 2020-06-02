# https://www.spoj.com/problems/STPAR/
while 1:
    n = int(input())
    if not n:
        break
    arr = [int(x) for x in input().split()]
    req = 1
    stack = []
    for item in arr:
        if item != req:
            while len(stack) and stack[-1]==req:
                req += 1
                stack.pop()
            stack.append(item)
        else:
            req+=1
    while len(stack) and stack[-1]==req:
        req += 1
        stack.pop()
    if req == n+1:
        print("yes")
    else:
        print("no")