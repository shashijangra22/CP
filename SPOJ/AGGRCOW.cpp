// https://www.spoj.com/problems/AGGRCOW/
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
#define endl "\n"

ll gcd(ll a, ll b){
	return (!b)?a:gcd(b,a%b);
}

vi makePrefix(vi &v){
	vi p(v.size()+1,0);
	loop(0,v.size()-1,1) p[i+1]=p[i]+v[i];
	return p;
}

void display(vi &v,string c){
	for(auto x:v) cout<<x<<c;
}

ll calCows(vi &v, ll mid){
	ll prev=v[0];
	ll count=1;
	loop(1,v.size()-1,1){
		if (v[i]-prev >= mid){
			prev=v[i];
			count++;
		}
	}
	return count;
}

ll solve(vi &v, ll C){
	ll low=0;
	ll high=v[v.size()-1]-v[0];
	while(low<high){
		ll mid=low+(high-low)/2+1;
		ll cows=calCows(v,mid);
		if (cows<C) high=mid-1;
		else low=mid;
	}
	return low;
}

int main(){
	IOS
	ll t,N,C;
	cin>>t;
	while(t--){
		cin>>N>>C;
		vi v(N);
		loop(0,N-1,1) cin>>v[i];
		sort(all(v));
		cout<<solve(v,C)<<endl;
	}
	return 0;
}
