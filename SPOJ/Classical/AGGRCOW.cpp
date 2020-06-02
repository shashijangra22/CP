// https://www.spoj.com/problems/AGGRCOW/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<ll>
#define vvi vector<vi>
#define loop(x,y,z) for(ll i=x; i<=y; i+=z)
#define rloop(x,y,z) for(ll i=x; i>=y; i-=z)
#define all(x) x.begin(), x.end()

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
