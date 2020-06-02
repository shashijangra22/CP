# https://www.spoj.com/problems/JULKA/
t = 10
def plus(a,b):
    a = a[::-1]
    b = b[::-1]
    mx = max(len(a),len(b))
    ans = ['0' for x in range(mx)]
    carry = 0
    for x in range(mx):
        if x < len(a):
            carry+=int(a[x])
        if x < len(b):
            carry+=int(b[x])
        ans[x] = chr(carry%10 + 48)
        carry = carry//10
    if carry:
        ans.append(chr(carry + 48))
    return "".join(ans[::-1])

def divideBy2(a):
    q = []
    i = 0
    borrow = 0
    while i<len(a):
        temp = borrow*10 + int(a[i])
        q.append(chr(temp//2 + 48))
        borrow = (1 if temp&1 else 0)
        i+=1
    for x in range(len(q)):
        if q[x]!='0':
            return "".join(q[x:])

def minus(a,b):
    zeros = len(a) - len(b)
    b = '0'*zeros + b
    a = a[::-1]
    b = b[::-1]
    borrow = 0
    ans = [0 for x in range(len(a))]
    for x in range(len(a)):
        i = int(a[x])
        j = int(b[x])
        ans[x] = i-j-borrow
        if ans[x]<0:
            ans[x]+=10
            borrow=1
        else:
            borrow=0
        ans[x] = chr(ans[x]+48)
    ans = ans[::-1]
    for x in range(len(ans)):
        if ans[x]!='0':
            return "".join(ans[x:])

while t:
    n = input()
    k = input()
    if n=='0' and k=='0':
        print(0)
        print(0)
        continue
    # print(minus(n,k))
    y = divideBy2(plus(n,k))
    print(y)
    x = minus(n,y)
    x = (0 if x is None else x)
    print(x)
    t-=1