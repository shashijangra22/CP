// https://www.spoj.com/problems/GCJ101BB/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<ll>
#define vvi vector<vi>
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
#define watch(x) cout<<(#x)<<" is "<<x
#define endl "\n"

ll gcd(ll a, ll b){
	return (!b)?a:gcd(b,a%b);
}

void display(vi &v,string c){
	for(auto x:v) cout<<x<<c;
}

int main(){
	IOS
	ll c,ans,blueChicks,redChicks,n,k,b,t,test=1;
	cin>>c;
	while(test<=c){
		cin>>n>>k>>b>>t;
		ans=0;
		blueChicks=redChicks=0;
		vi pos(n),v(n);
		loop(0,n-1,1) cin>>pos[i];
		loop(0,n-1,1) cin>>v[i];
		rloop(n-1,0,1){
			if(redChicks==k) break;
			if(pos[i]+v[i]*t < b){
				blueChicks++;
			}
			else{
				redChicks++;
				ans+=blueChicks;
			}
		}
		cout<<"Case #"<<test<<": ";
		if(redChicks>=k) cout<<ans<<endl;
		else cout<<"IMPOSSIBLE\n";
		test++;
	}
	return 0;
}
