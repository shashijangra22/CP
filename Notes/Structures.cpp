// segment tree with point updates

struct SegTree{
	vector<ll> tree;
	int n;
	
	SegTree(vi &arr,ll sz){
		n = sz;
		tree.resize(2*n);
		loop(i,0,n-1,1) tree[i+n] = arr[i];
		loopR(i,n-1,1,1) tree[i] = tree[2*i] + tree[2*i + 1];
	}

	void update(int idx, ll val){
		idx--;
		idx+=n;
		tree[idx] = val;
		idx>>=1;
		while(idx){
			tree[idx] = tree[2*idx] + tree[2*idx + 1];
			idx>>=1;
		}
	}

	ll query(int l, int r){ // range [l,r)
		l--;
		r--;
		l+=n;
		r+=n;
		ll sum = 0;
		while (l < r){
			if (l&1) sum+=tree[l++];
			if (r&1) sum+=tree[--r];
			l>>=1;
			r>>=1;
		}
		return sum;
	}
};

// DSU

struct DSU{
	vector<int> parent,low,high;
	ll comps;

	DSU(int n){
		parent.resize(n+1);
		iota(all(parent),0);
		low=high=parent;
		comps=n;
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
		comps--;
		return true;
	}

	int getHigh(int x){
		return high[FIND(x)];
	}

	int getLow(int x){
		return low[FIND(x)];
	}
};

// minQueue

struct minQ{
	deque<int> dq;
	
	void PUSH(int ind){
		while(dq.size() and arr[dq.back()] >= arr[ind]) dq.pop_back();
		dq.push_back(ind);
	}

	void POP(int ind){
		while(dq.size() and dq.front() <= ind) dq.pop_front();
	}

	int front(){
		return dq.front();
	}
};

// BIT

struct BIT{
	int n;
	vector<int> tree;

	BIT(int sz){
		n = sz;
		tree.resize(n+1);
	}
	void update(int idx,int val){
		while(idx <= n){
			tree[idx]+=val;
			idx += (idx & -idx);
		}
	}
	int query(int idx){
		int sum = 0;
		while(idx){
			sum += tree[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}
	int sum(int l, int r){
		return query(r)-query(l-1);
	}
	int getKth(int k){
		int low=1,high=n,mid;
		while(low < high){
			mid=(low+high)/2;
			if(query(mid) >= k) high=mid;
			else low=mid+1;
		}
		return low;
	}
};