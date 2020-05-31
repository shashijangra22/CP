// https://www.spoj.com/problems/LCA/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<ll>
#define vvi vector<vi>
#define P_Q priority_queue<ll>
#define p_q priority_queue<ll,vi,greater<ll>>
#define loop(i,x,y,z) for(int i=x; i<=y; i+=z)
#define loopR(i,x,y,z) for(int i=x; i>=y; i-=z)
#define all(x) begin(x), end(x)
#define allR(x) rbegin(x), rend(x)
#define watch(x) cout<<(#x)<<" is "<<x<<'\n'
#define display(v,c) for(auto x:v) cout<<x<<c;
#define endl "\n"

const ll N = 200005;

vvi adj(N);
vi euler;
vi first(N);
vi height(N);

struct SegTree
{
	vector<ll> tree;
	int n;

	SegTree(vi &arr, ll sz)
	{
		n = sz;
		tree.resize(2 * n);
		loop(i, 0, n - 1, 1) tree[i + n] = arr[i];
		loopR(i,n-1,1,1){
			ll h1 = height[tree[2*i]];
			ll h2 = height[tree[2*i + 1]];
			if (h1 < h2) tree[i] = tree[2*i];
			else tree[i] = tree[2*i + 1];
		}
	}

	ll query(int l, int r)
	{
		l--;
		r--;
		l += n;
		r += n;
		r+=1;
		ll mn = tree[l];
		while (l < r)
		{
			if (l & 1){
				if (height[tree[l]] < height[mn]) mn = tree[l];
				l++;
			}
			if (r & 1){
				--r;
				if (height[tree[r]] < height[mn]) mn = tree[r];
			}
			l >>= 1;
			r >>= 1;
		}
		return mn;
	}
};


void dfs(ll node, ll prev, ll depth){
	height[node] = depth;
	euler.push_back(node);
	first[node] = euler.size();
	for(auto x:adj[node]){
		if (x!=prev){
			dfs(x,node,depth+1);
			euler.push_back(node);
		}
	}
}

ll LCA(ll u, ll v, SegTree &tree){
	ll l = first[u];
	ll r = first[v];
	if(l > r) swap(l,r);
	return tree.query(l,r)+1;
}

int main(){
	IOS
	// do magic here
	ll tests,n,m,q,a,b;
	cin>>tests;
	loop(t,1,tests,1){
		cout<<"Case "<<t<<":\n";
		cin>>n;
		loop(a,1,n,1){
			cin>>m;
			adj[a-1].clear();
			loop(j,1,m,1){
				cin>>b;
				adj[a-1].push_back(b-1);
				adj[b-1].push_back(a-1);
			}
		}
		euler.clear();
		dfs(0,0,0);
		SegTree tree(euler,euler.size());
		cin>>q;
		while(q--){
			cin>>a>>b;
			cout<<LCA(a-1,b-1,tree)<<endl;
		}
	}
	return 0;
}