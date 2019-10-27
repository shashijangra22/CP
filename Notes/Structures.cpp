// segment tree with point updates

const int MAX = (int)1e5 + 777;  // limit for array size
ll TREE[2 * MAX];

void build() { loopR(i,n-1,1,1) TREE[i]=TREE[i<<1] + TREE[i<<1|1]; }

void update(ll x,ll p) {
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

// DSU

vector<ll> parent(n); // initially self
vector<ll> sizes(n,1); // initially 1
 
ll FIND(ll a){ return (a==parent[a])?a:parent[a]=FIND(parent[a]); }

bool CHECK(ll a, ll b) { return FIND(a)==FIND(b); }

void JOIN(ll a, ll b) { parent[FIND(b)]=FIND(a); } // naive union

void UNION(ll a, ll b){ // union by size
	ll xRoot=FIND(a),yRoot=FIND(b);
	if(xRoot==yRoot) return;
	if(sizes[xRoot]<sizes[yRoot]) swap(xRoot,yRoot);
	parent[yRoot]=xRoot;
	sizes[xRoot]+=sizes[yRoot];
}