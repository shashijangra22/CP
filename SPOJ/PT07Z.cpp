// https://www.spoj.com/problems/PT07Z/
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

vvi adj;
vi visited;

pll dfs(ll node){
	visited[node]=1;
	pll extreme={node,-1};
	for(auto x:adj[node]){
		if(not visited[x]){
			pll temp = dfs(x);
			if(temp.second > extreme.second) extreme = temp;
		}
	}
	return {extreme.first,extreme.second + 1};
}

int main(){
	IOS
	// do magic here
	ll n,u,v;
	cin>>n;
	adj.resize(n);
	visited.resize(n,0);
	loop(i,1,n-1,1){
		cin>>u>>v;
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}
	pll extreme1 = dfs(0);
	fill(all(visited),0);
	pll extreme2 = dfs(extreme1.first);
	cout<<extreme2.second;
	return 0;
}