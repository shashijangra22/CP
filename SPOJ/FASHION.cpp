// https://www.spoj.com/problems/FASHION/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<ll>
#define vvi vector<vi>
#define uSet unordered_set<ll>
#define oSet set<ll>
#define Q queue<ll>
#define DQ deque<ll> 
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back
#define mp make_pair
#define mt make_tuple
#define f first
#define s second
#define ub upper_bound
#define lb lower_bound
#define loop(x,y,z) for(ll i=x; i<=y; i+=z)
#define rloop(x,y,z) for(ll i=x; i>=y; i-=z)
#define all(x) x.begin(), x.end()
#define sum(x) accumulate(all(x),0LL)
#define minE(x) *min_element(all(x))
#define maxE(x) *max_element(all(x))
#define mem(a,b) memset(a,b,sizeof(a))
#define endl "\n"

ll gcd(ll a, ll b){
	return (!b)?a:gcd(b,a%b);
}

int main(){
	IOS
	ll t,n,ans;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		vi v1(n),v2(n);
		loop(0,n-1,1) cin>>v1[i];
		loop(0,n-1,1) cin>>v2[i];
		sort(all(v1));
		sort(all(v2));
		loop(0,n-1,1)
			ans+=(v1[i]*v2[i]);
		cout<<ans<<"\n";
	}
	return 0;
}
