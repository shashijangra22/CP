# Segment Tree with point updates


class SegTree:

    def __init__(self, arr, n):
        self.n = n
        self.tree = [0 for x in range(n)] + [x for x in arr]
        for x in range(n-1, 0, -1):
            self.tree[x] = self.tree[2*x] + self.tree[2*x + 1]

    def query(self, l, r):    # sum of range [l,r)
        l -= 1
        r -= 1
        l += n
        r += n
        s = 0
        while l < r:
            if l & 1:
                s += self.tree[l]
                l += 1
            if r & 1:
                r -= 1
                s += self.tree[r]
            l = l >> 1
            r = r >> 1
        return s

    def update(self, idx, val):
        idx -= 1
        idx += self.n
        self.tree[idx] = val
        idx = idx >> 1
        while idx:
            self.tree[idx] = self.tree[2*idx] + self.tree[2*idx + 1]
            idx = idx >> 1

    def getKth(self, k):
        low, high = 1, self.n
        while low < high:
            mid = (low+high)//2
            if self.query(1, mid) < k:
                low = mid + 1
            else:
                high = mid
        return low

# BIT with point updates


class BIT:

    def __init__(self, arr, n):
        self.n = n
        self.tree = [0 for x in range(self.n+1)]

    def update(self, idx, val):
        while idx <= self.n:
            self.tree[idx] += val
            idx += (idx & -idx)

    def query(self, idx):
        s = 0
        while idx:
            s += self.tree[idx]
            idx -= (idx & -idx)
        return s

    def getKth(self, k):
        low, high = 1, self.n
        while low < high:
            mid = (low+high)//2
            if self.query(mid) < k:
                low = mid + 1
            else:
                high = mid
        return low

# DSU with size and path compression heuristics


class DSU:

    def __init__(self, n):
        self.n = n
        self.comps = n
        self.parent = [i for i in range(n)]
        self.size = [1 for i in range(n)]

    def FIND(self, x):
        if x != self.parent[x]:
            self.parent[x] = self.FIND(self.parent[x])
        return self.parent[x]

    def UNION(self, x, y):
        x, y = self.FIND(x), self.FIND(y)
        if x == y:
            return 0
        self.comps -= 1
        if self.size[x] > self.size[y]:
            x, y = y, x
        self.parent[x] = y
        self.size[y] += self.size[x]
        return 1


class Trie:

    def __init__(self):
        self.arr = {}
        self.count = 0
        self.end = 0

    def insert(self, word):
        for x in word:
            if x not in self.arr:
                self.arr[x] = Trie()
            self = self.arr[x]
            self.count += 1
        self.end = True

    def findPrefix(self, word):
        for x in word:
            if x not in self.arr:
                return 0, 0
            self = self.arr[x]
        return self.end, self.count


class BitTrie:

    def __init__(self):
        self.arr = [None, None]

    def insert(self, num):
        for x in range(31, -1, -1):
            bit = (num >> x) & 1
            if self.arr[bit] is None:
                self.arr[bit] = BitTrie()
            self = self.arr[bit]
        self.ends = True

    def XorMaxQuery(self, num):
        ans = 0
        for x in range(31, -1, -1):
            bit = (num >> x) & 1
            bit = bit ^ 1 if self.arr[bit ^ 1] else bit
            self = self.arr[bit]
            ans = (ans << 1) | bit
        return ans ^ num
