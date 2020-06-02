// https://www.spoj.com/problems/PR003004/
#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
// typedef tree <ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> set_t;
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

ll dp[20][200][2];
vi B;
ll solve(int ind, ll s, int flag){
	if (ind==B.size()) return s;
	if (dp[ind][s][flag]!=-1) return dp[ind][s][flag];
	ll temp=0;
	int jhanda=flag;
	loop(d,0,9,1){
		if (flag==1){
			if (d==B[ind]) jhanda=1;
			if (d<B[ind]) jhanda=0;
			if (d>B[ind]) break;
		}
		temp+=solve(ind+1,s+d, jhanda);
	}
	return dp[ind][s][flag]=temp;
}

void makeVector(ll x){
	while(x){
		B.pb(x%10);
		x/=10;
	}
	reverse(all(B));
}

int main(){
	IOS
	// do magic here
	ll t,a,b,ans1,ans2;
	cin>>t;
	while(t--){
		cin>>a>>b;
		B.clear();
		memset(dp,-1,sizeof(dp));
		makeVector(b);
		ans1=solve(0,0,1);
		B.clear();
		memset(dp,-1,sizeof(dp));
		makeVector(a-1);
		ans2=solve(0,0,1);
		cout<<ans1-ans2<<endl;
	}
	return 0;
}
