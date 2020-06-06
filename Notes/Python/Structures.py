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

# BIT with point updates


class BIT:

    def __init__(self, arr, n):
        self.n = n
        self.tree = [0 for x in range(n+1)]

    def update(self, idx, val):
        while idx <= n:
            self.tree[idx] += val
            idx += (idx & -idx)

    def query(self, idx):
        s = 0
        while idx:
            s += self.tree[idx]
            idx -= (idx & -idx)
        return s

# DSU with random Union


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

    def getSize(self, x):
        return self.size[self.FIND(x)]

    def UNION(self, x, y):
        xRoot = self.FIND(x)
        yRoot = self.FIND(y)
        if xRoot != yRoot:
            self.comps -= 1
            if random.randint(1, 100) & 1:
                self.parent[xRoot] = yRoot
                self.size[yRoot] += self.size[xRoot]
            else:
                self.parent[yRoot] = xRoot
                self.size[xRoot] += self.size[yRoot]
            return 1
        return 0


class Trie:

    def __init__(self):
        self.arr = {}
        self.count = 0
        self.end = 0

    def insert(self, word):
        root = self
        for x in word:
            if x not in root.arr:
                root.arr[x] = Trie()
            root = root.arr[x]
            root.count += 1
        root.end = True

    def findPrefix(self, word):
        root = self
        for x in word:
            if x not in root.arr:
                return 0, 0
            root = root.arr[x]
        return root.end, root.count


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

    def query(self, num):
        ans = 0
        for x in range(31, -1, -1):
            bit = (num >> x) & 1
            bit = bit ^ 1 if self.arr[bit ^ 1] else bit
            self = self.arr[bit]
            ans = (ans << 1) | bit
        return ans ^ num
