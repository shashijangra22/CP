# Segment Tree with point updates

class SegTree:
    
    def __init__(self,arr,n):
        self.n = n
        self.tree = [0 for x in range(n)] + [x for x in arr]
        for x in range(n-1,0,-1):
            self.tree[x] = self.tree[2*x] + self.tree[2*x + 1]
    
    def query(self,l,r):    # sum of range [l,r)
        l-=1
        r-=1
        l+=n
        r+=n
        s = 0
        while l < r:
            if l&1:
                s += self.tree[l]
                l+=1
            if r&1:
                r-=1
                s += self.tree[r]
            l=l>>1
            r=r>>1
        return s
    
    def update(self,idx,val):
        idx-=1
        idx += self.n
        self.tree[idx] = val
        idx = idx>>1
        while idx:
            self.tree[idx] = self.tree[2*idx] + self.tree[2*idx + 1]
            idx = idx>>1

# BIT with point updates

class BIT:
    
    def __init__(self,arr,n):
        self.n = n
        self.tree = [0 for x in range(n+1)]
    def update(self,idx,val):
        while idx<=n:
            self.tree[idx]+=val
            idx += (idx & -idx)
    def query(self,idx):
        s = 0
        while idx:
            s += self.tree[idx]
            idx -= (idx & -idx)
        return s