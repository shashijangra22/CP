def modPow(a, b, m):  # modular exponentiation
    a %= m
    res = 1
    while b:
        if b & 1:
            res = (res*a) % m
        a = (a*a) % m
        b >>= 1
    return res % m


def modInv(n, p):  # modular Inverse if p is prime
    return modPow(n, p-2, p)


def gcd(a, b):  # gcd
    if not b:
        return a
    return gcd(b, a % b)


def lcm(a, b):  # lcm
    return a//gcd(a, b) * b


def gcdExt(a, b):  # gcd extended
    if not b:
        return [a, 1, 0]
    g, x1, y1 = gcdExt(b, a % b)
    x = y1
    y = x1-y1*(a//b)
    return [g, x, y]


def modInv(a, m):   # modular inverse general case
    g, x, y = gcdExt(a, m)
    if g != 1:
        return None
    x = ((x % m)+m) % m
    return x
