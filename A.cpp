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
int main(){
	IOS
	ll n,temp,last=0,ans=1;
	cin>>n;
	vector<pair<ll,ll>> v;
	vi b(n,0);
	loop(0,n-1,1){
		cin>>temp;
		v.pb({temp,i});
	}
	temp=v[0].first;
	rloop(n-1,0,1){
		if(v[i].first==temp){
			last=i;
			break;
		}
	}
	loop(0,last,1) b[i]=1;
	sort(all(v));
	ll i=0;
	ll end=0;
	while(i<v.size()){
		temp=v[i].first;
		ll start=v[i].second;
		if(b[start]==0){
			b[start]=2;
		}
		i++;
		start++;
		while(i<v.size() && temp==v[i].first){
			i++;
		}
		if(start<=v[i-1].second)
			intervals.pb({start,v[i-1].second});
		// for(int k=start; k<=v[i-1].second; k++) b[k]=1;
	}
	for(auto x:b){
		ans=(ans*x)%998244353;
	}
	cout<<ans;
	return 0;
}