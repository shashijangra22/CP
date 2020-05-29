// modular exponentiation
ll modPow(ll a, ll b, ll m)
{
    ll res = 1;
    a = a % m;
    while (b)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res % m;
}

// modular inverse
ll modInv(ll n, ll p) // if p is prime
{
    return modPow(n, p - 2, p);
}

// gcd
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

// lcm
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

// gcd extended
ll gcdExt(ll a, ll b, ll &x, ll &y)
{
    if (not b)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = gcdExt(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}
