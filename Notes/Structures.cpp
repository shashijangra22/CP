// segment tree with point updates

struct SegTree{
	const int MAX = (int)1e5 + 777;
	ll TREE[2 * MAX]={0};
	ll n;

	SegTree(vector<ll> arr,int sz){
		n=sz;
		loop(i,0,n-1,1) TREE[i+n]=arr[i];
		loopR(i,n-1,1,1) TREE[i]=TREE[i<<1] + TREE[i<<1|1];
	}

	void update(int p, ll x){
		p--; // matching index
		p+=n;
		TREE[p]=x;
		for (;p > 0; p >>= 1) TREE[p>>1] = TREE[p] + TREE[p^1];
	}

	ll query(int l, int r){
		ll ans=0;
		--l,--r;
		l+=n,r+=n;
		r++;
		while(l < r) {
		    if (l&1) ans+=TREE[l++];
			if (r&1) ans+=TREE[--r];
			l>>=1;
			r>>=1;
		}
		return ans;
	}
}

// DSU

struct DSU{
	vector<int> parent,low,high;

	DSU(int n){
		parent.resize(n);
		iota(all(parent),0);
		low=high=parent;
	}

	int FIND(int x){
		if (parent[x]==x) return x;
		return parent[x]=FIND(parent[x]);
	}

	bool UNION(int u, int v){
		u=FIND(u),v=FIND(v);
		if (u==v) return false;
		low[u]=min(low[u],low[v]);
		high[u]=max(high[u],high[v]);
		parent[v]=u;
		return true;
	}

	int getHigh(int x){
		return high[FIND(x)];
	}

	int getLow(int x){
		return low[FIND(x)];
	}
};