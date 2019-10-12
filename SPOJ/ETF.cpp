// https://www.spoj.com/problems/ETF/
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

#define MX 1000000

vi phi(MX+1,0);

void precompute(){
	loop(i,1,MX,1) phi[i]=i;
	loop(i,2,MX,1){
		if (phi[i]==i){
			phi[i]--;
			loop(j,i+i,MX,i) phi[j]=(phi[j]/i)*(i-1);
		}
	}
}

int main(){
	IOS
	// do magic here
	precompute();
	ll test,n;
	cin>>test;
	while(test--){
		cin>>n;
		cout<<phi[n]<<endl;
	}
	return 0;
}
