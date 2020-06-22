// https://www.spoj.com/problems/SUBMERGE/
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


// detecting bridges in a graph
struct Graph
{
	vi visited, low, disc;
	vvi adj;
	set<ll> AP;
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
		ll children=0;
		for (auto x : adj[node])
		{
			if (x == par) continue;
			if (visited[x]) low[node] = min(low[node], disc[x]);
			else
			{
				dfs(x, node);
				children++;
				low[node] = min(low[node], low[x]);
				if (low[x] >= disc[node] and par!=-1) AP.insert(node);
			}
		}
		if(par==-1 and children>1) AP.insert(node);
	}

	void detectAP(){
		dfs(1,-1);
	}
};

int main(){
	IOS
	// do magic here
	ll n,m,u,v;
	while(1){
		cin>>n>>m;
		if (not n and not m) break;
		Graph G(n);
		loop(i,1,m,1){
			cin>>u>>v;
			G.addEdge(u,v);
		}
		G.detectAP();
		cout<<G.AP.size()<<endl;
	}
	return 0;
}