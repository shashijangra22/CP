// https://code.google.com/codejam/contest/2924486/dashboard#s=p4
#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define loop(i,x,y,z) for(int i=x; i<=y; i+=z)
#define ADJ map<int,vector<pair<int,int>>>

struct DSU{
	vector<int> parent;
	DSU(int n){
		parent.resize(n);
		iota(parent.begin(),parent.end(),0);
	}

	int FIND(int x){
		if(parent[x]!=x){
			parent[x]=FIND(parent[x]);
		}
		return parent[x];
	}

	bool UNION(int u, int v){
		u=FIND(u);
		v=FIND(v);
		if (u==v) return false;
		if(rand()&1) parent[u]=v;
		else parent[v]=u;
		return true;
	}

	set<int> getComps(){
		set<int> comps;
		loop(i,0,parent.size()-1,1) comps.insert(FIND(i));
		return comps;
	}
};

int shortestPath(int u, int v, ADJ &adj,set<int> &parents){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
	map<int,int> dist,visited;
	for(auto x:parents) dist[x]=INT_MAX;
	dist[u]=0;
	Q.push({0,u});
	while(!Q.empty()){
		pair<int,int> node=Q.top();
		Q.pop();
		// visited[u]=true;
		for(auto x:adj[node.second]){
			int newCost=x.second + node.first;
			if(newCost < dist[x.first]){
				dist[x.first]=newCost;
				Q.push({dist[x.first],x.first});
			}
		}
	}
	return ((dist[v]==INT_MAX)?-1:dist[v]);
}

int main(){
	IOS
	// do magic here
	int tests,n,m,u,v,w,S;
	string color;
	cin>>tests;
	loop(t,1,tests,1){
		cout<<"Case #"<<t<<":\n";
		cin>>n;
		DSU dsu(n);
		map<string,vector<int>> colorMap;
		loop(i,0,n-1,1){
			cin>>color;
			colorMap[color].push_back(i);
		}
		for(auto clr:colorMap){
			int root=clr.second[0];
			for(auto x:clr.second){
				dsu.UNION(root,x);
			}
		}
		set<int> parents=dsu.getComps();
		ADJ adj;
		cin>>m;
		while(m--){
			cin>>u>>v>>w;
			u=dsu.FIND(u-1);
			v=dsu.FIND(v-1);
			if(u!=v) adj[u].push_back({v,w});
		}
		cin>>S;
		while(S--){
			cin>>u>>v;
			u=dsu.FIND(u-1);
			v=dsu.FIND(v-1);
			if(u==v) cout<<0;
			else cout<<shortestPath(u,v,adj,parents);
			cout<<endl;
		}
	}
	return 0;
}