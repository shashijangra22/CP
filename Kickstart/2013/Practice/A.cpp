// https://code.google.com/codejam/contest/dashboard?c=2933486#s=p0

#include<bits/stdc++.h>
using namespace std;
// include <ext/pb_ds/assoc_container.hpp>
// include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
#define ll long long
#define pll pair<ll,ll>
// typedef tree <ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<ll>
#define vvi vector<vi>
#define P_Q priority_queue<ll>
#define p_q priority_queue<ll,vi,greater<ll>>
#define pb push_back
#define popb pop_back
#define ub upper_bound
#define lb lower_bound
#define loop(i,x,y,z) for(int i=x; i<=y; i+=z)
#define loopR(i,x,y,z) for(int i=x; i>=y; i-=z)
#define all(x) begin(x), end(x)
#define allR(x) rbegin(x), rend(x)
#define sum(x) accumulate(all(x),0LL)
#define minE(x) *min_element(all(x))
#define maxE(x) *max_element(all(x))
#define watch(x) cout<<(#x)<<" is "<<x<<'\n'
#define display(v,c) for(auto x:v) cout<<x<<c
#define setbits(x) __builtin_popcount(x)
#define ctoi(x) (int)((x)-'a')
#define endl "\n"
#define printCase(c,x) cout<<"Case #"<<c<<": "<<ans<<endl

map<string,vector<string>> adj;
map<string,int> visited;
map<string,int> colorOf;

bool dfs(string node, int color){
	visited[node]=1; // visiting
	colorOf[node]=color;
	for(auto x:adj[node]){
		if(not visited[x]){
			if(not dfs(x,3-color)){
				return false;
			}
		}
		else if(visited[x]==1){
			if(colorOf[x]==color) return false;
		}
	}
	visited[node]=2;
	return true;
}

int main(){
	// do magic here
	int t,m;
	string str1,str2;
	cin>>t;
	loop(test,1,t,1){
		cin>>m;
		adj.clear();
		visited.clear();
		while(m--){
			cin>>str1>>str2;
			adj[str1].pb(str2);
			adj[str2].pb(str1);
		}
		string ans=((dfs((*adj.begin()).first,1))?"Yes":"No");
		printCase(test,ans);
	}
	return 0;
}