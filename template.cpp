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
#define display(v,c) for(auto x:v) cout<<x<<c;
#define setbits(x) __builtin_popcount(x)
#define ctoi(x) (int)((x)-'a')
#define endl "\n"

ll n,m;

pll check(vvi &v, ll mid){
	map<ll,ll> masks;
	ll mask;
	loop(i,0,n-1,1){
		mask=0;
		loop(j,0,m-1,1){
			if(v[i][j]>=mid) mask |= (1<<j);
		}
		masks[mask]=i;
	}
	for(auto x:masks){
		for(auto y:masks){
			if((x.first|y.first) == (1<<m)-1) return {x.second,y.second};
		}
	}
	return {-1,-1};
}

int main(){
	IOS
	// do magic here
	cin>>n>>m;
	vvi v(n);
	loop(i,0,n-1,1){
		v[i].resize(m);
		loop(j,0,m-1,1) cin>>v[i][j];
	}
	ll low=0,high=INT_MAX,mid;
	while(low<high){
		mid=(low+high+1)/2;
		pll tmp=check(v,mid);
		if(tmp.first!=-1 and tmp.second!=-1) low=mid;
		else high=mid-1;
	}
	pll ans=check(v,low);
	cout<<ans.first+1<<" "<<ans.second+1;
	return 0;
}