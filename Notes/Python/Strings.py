def rabinKarp(string, text):
    S = len(string)
    T = len(text)
    mx = max(S, T)
    if T < mx:
        return []
    p, m = 31, int(1e9)+9
    powers = [1 for x in range(mx)]
    for i in range(1, mx):
        powers[i] = (powers[i-1]*p) % m
    hashes = [0 for x in range(T+1)]
    for i in range(T):
        hashes[i+1] = (hashes[i] + ((ord(text[i])-96)*powers[i]) % m) % m
    hashS = 0
    for i in range(S):
        hashS = (hashS + ((ord(string[i])-96)*powers[i]) % m) % m
    occ = []
    for i in range(T-S+1):
        currHash = (hashes[i+S]-hashes[i]+m) % m
        if currHash == (hashS * powers[i] % m):
            occ.append(i)
    return occ