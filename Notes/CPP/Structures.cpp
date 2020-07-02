// segment tree with point updates

struct SegTree
{
	vector<ll> tree;
	int n;

	SegTree(vi &arr, ll sz)
	{
		n = sz;
		tree.resize(2 * n);
		loop(i, 0, n - 1, 1) tree[i + n] = arr[i];
		loopR(i, n - 1, 1, 1) tree[i] = tree[2 * i] + tree[2 * i + 1];
	}

	void update(int idx, ll val)
	{
		idx--;
		idx += n;
		tree[idx] = val;
		idx >>= 1;
		while (idx)
		{
			tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
			idx >>= 1;
		}
	}

	ll query(int l, int r)
	{ // range [l,r)
		l--;
		r--;
		l += n;
		r += n;
		ll sum = 0;
		while (l < r)
		{
			if (l & 1)
				sum += tree[l++];
			if (r & 1)
				sum += tree[--r];
			l >>= 1;
			r >>= 1;
		}
		return sum;
	}
};

// DSU

struct DSU
{
	vector<int> parent, low, high, size;
	ll comps;

	DSU(int n)
	{
		parent.resize(n + 1);
		size.resize(n + 1);
		fill(all(size), 1);
		iota(all(parent), 0);
		low = high = parent;
		comps = n;
	}

	int FIND(int x)
	{
		if (parent[x] == x)
			return x;
		return parent[x] = FIND(parent[x]);
	}

	bool UNION(int u, int v)
	{
		u = FIND(u), v = FIND(v);
		if (u == v)
			return false;
		low[u] = min(low[u], low[v]);
		high[u] = max(high[u], high[v]);
		if (rand() & 1)
		{
			parent[v] = u;
			size[u] += size[v];
		}
		else
		{
			parent[u] = v;
			size[v] += u;
		}
		comps--;
		return true;
	}

	int getSize(int x)
	{
		return size[FIND(x)];
	}

	int getHigh(int x)
	{
		return high[FIND(x)];
	}

	int getLow(int x)
	{
		return low[FIND(x)];
	}
};

// minQueue

struct minQ
{
	deque<int> dq;

	void PUSH(int ind)
	{
		while (dq.size() and arr[dq.back()] >= arr[ind])
			dq.pop_back();
		dq.push_back(ind);
	}

	void POP(int ind)
	{
		while (dq.size() and dq.front() <= ind)
			dq.pop_front();
	}

	int front()
	{
		return dq.front();
	}
};

// BIT

struct BIT
{
	int n;
	vector<int> tree;

	BIT(int sz)
	{
		n = sz;
		tree.resize(n + 1);
	}
	void update(int idx, int val)
	{
		while (idx <= n)
		{
			tree[idx] += val;
			idx += (idx & -idx);
		}
	}
	int query(int idx)
	{
		int sum = 0;
		while (idx)
		{
			sum += tree[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}
	int sum(int l, int r)
	{
		return query(r) - query(l - 1);
	}
	int getKth(int k)
	{
		int low = 1, high = n, mid;
		while (low < high)
		{
			mid = (low + high) / 2;
			if (query(mid) >= k)
				high = mid;
			else
				low = mid + 1;
		}
		return low;
	}
};

// TRIE

struct TRIE
{
	struct TRIE *arr[26] = {NULL};
	int count, end;

	void insert(string word)
	{
		TRIE *root = this;
		for (auto x : word)
		{
			if (!root->arr[x - 'a'])
				root->arr[x - 'a'] = new TRIE();
			root = root->arr[x - 'a'];
			root->count += 1;
		}
		root->end = 1;
	}

	pair<int, int> searchPrefix(string word)
	{
		TRIE *root = this;
		for (auto x : word)
		{
			if (!root->arr[x - 'a'])
				return {0, 0};
			root = root->arr[x - 'a']
		}
		return { root->end, root->count }
	}
};

struct BitTrie
{
	struct BitTrie *arr[2] = {NULL};

	void insert(int num)
	{
		BitTrie *root = this;
		int i = 32;
		while (i--)
		{
			int bit = (num >> i) & 1;
			if (!root->arr[bit])
				root->arr[bit] = new BitTrie();
			root = root->arr[bit];
		}
	}

	int XorMaxQuery(int num)
	{
		int ans = 0;
		BitTrie *root = this;
		int i = 32;
		while (i--)
		{
			int bit = (num >> i) & 1;
			bit = (root->arr[bit ^ 1]) ? bit ^ 1 : bit;
			ans = (ans << 1) | bit;
			root = root->arr[bit];
		}
		return ans ^ num;
	}
};

// detecting bridges and articulation points in a graph
struct Graph
{
	vi visited, low, disc;
	vector<pll> bridges;
	set<ll> AP;
	vvi adj;
	ll timer = 0;
	Graph(ll n)
	{
		adj.resize(n + 1);
		visited.assign(n + 1, 0);
		low.assign(n + 1, -1);
		disc.assign(n + 1, -1);
	}

	void addEdge(ll u, ll v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void dfs(ll node, ll par)
	{
		visited[node] = 1;
		low[node] = disc[node] = timer++;
		ll children = 0;
		for (auto x : adj[node])
		{
			if (x == par)
				continue;
			if (visited[x])
				low[node] = min(low[node], disc[x]);
			else
			{
				dfs(x, node);
				children++;
				low[node] = min(low[node], low[x]);
				if (low[x] > disc[node])
					bridges.push_back({min(x, node), max(x, node)});
				if (low[x] >= disc[node] and par != -1)
					AP.insert(node);
			}
		}
		if (par == -1 and chidren > 1)
			AP.insert(node);
	}

	void detectBridges()
	{
		loop(i, 1, adj.size() - 1, 1) if (not visited[i]) dfs(i, -1);
		sort(all(bridges));
	}

	void detectAP()
	{
		dfs(1, -1);
	}
};

struct suffixArray
{
	vi p, c;
	string str;
	vector<pair<pll, ll>> a;
	int n = 0, k = 0;
	suffixArray(string &s)
	{
		str = s + '$';
		n = str.size();
		p.resize(n);	// suffix array
		c.resize(n); 	// equivalence classes
		a.resize(n);	// array to be sorted based on c
	}

	void radix_sort(int ele)
	{
		vi pos(n),cnt(n);
		for (auto x : a) if (ele) cnt[x.first.second]++; else cnt[x.first.first]++;
		pos[0] = 0;
		loop(i, 1, n - 1, 1) pos[i] = pos[i - 1] + cnt[i - 1];
		vector<pair<pll, ll>> a_new(n);
		for (auto x : a)
		{
			int i = (ele) ? x.first.second : x.first.first;
			a_new[pos[i]] = x;
			pos[i]++;
		}
		a = a_new;
	}

	void assignClasses()
	{
		loop(i, 0, n - 1, 1) p[i] = a[i].second;
		c[p[0]] = 0;
		loop(i, 1, n - 1, 1) c[p[i]] = c[p[i - 1]] + (a[i].first != a[i - 1].first);
	}

	void buildSuffixArray()
	{
		loop(i, 0, n - 1, 1) a[i] = {{str[i], str[i]}, i};
		sort(all(a)); // k = 0
		assignClasses();
		while ((1 << k) < n) // k -> k + 1
		{
			loop(i, 0, n - 1, 1) a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
			radix_sort(1);
			radix_sort(0);
			// sort(all(a));
			assignClasses();
			k++;
		}
	}

	string check(ll mid, ll sz){
		ll ind = p[mid];
		ll chars = min(n - ind, sz);
		return str.substr(ind,chars);
	}
	
	ll lastOcc(string &query){
		if (query.size() >= str.size()) return 0;
		ll low = 1,high = n - 1;
		while (low < high){
			ll mid = (low+high)/2;
			if (query <= check(mid,query.size())) high = mid;
			else low = mid + 1;
		}
		if (check(low,query.size()) == query) return low;
		return 0;
	}

	ll firstOcc(string &query){
		if (query.size() >= str.size()) return 0;
		ll low = 1,high = n-1;
		while(low < high){
			ll mid = (low+high+1)/2;
			if( query >= check(mid,query.size())) low = mid;
			else high = mid - 1;
		}
		if (check(low,query.size()) == query) return low;
		return 0;
	}
};