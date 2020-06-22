// https://www.spoj.com/problems/EC_P/
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

struct Graph{
	vi visited,low,disc;
	vector<pll> bridges;
	vvi adj;
	ll timer=0;
	Graph(ll n, ll m){
		adj.resize(n+1);
		visited.assign(n+1,0);
		low.assign(n+1,-1);
		disc.assign(n+1,-1);
	}

	void addEdge(ll u, ll v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void dfs(ll node, ll par){
		visited[node]=1;
		low[node]=disc[node]=timer++;
		for(auto x:adj[node]){
			if (x==par) continue;
			if (visited[x]) low[node] = min(low[node],low[x]);
			else{
				dfs(x,node);
				low[node]=min(low[node],low[x]);
				if (low[x] > disc[node]) bridges.push_back({min(x,node),max(x,node)});
			}
		}
	}

	void detectBridges(){
		loop(i,1,adj.size()-1,1) if (not visited[i]) dfs(i,-1);
		sort(all(bridges));
	}

};

int main(){
	IOS
	// do magic here
	ll tests,n,m,u,v;
	cin>>tests;
	loop(t,1,tests,1){
		cin>>n>>m;
		Graph G(n,m);
		loop(i,1,m,1){
			cin>>u>>v;
			G.addEdge(u,v);
		}
		G.detectBridges();
		cout<<"Caso #"<<t<<endl;
		if(G.bridges.size()){
			cout<<G.bridges.size()<<endl;
			for(auto x:G.bridges) cout<<x.first<<" "<<x.second<<endl;
		}
		else cout<<"Sin bloqueos\n";
	}
	return 0;
}