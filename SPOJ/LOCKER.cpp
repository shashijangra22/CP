// https://www.spoj.com/problems/LOCKER/
#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define pll pair<ll,ll>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<ll>
#define vvi vector<vi>
#define P_Q priority_queue<ll>
#define p_q priority_queue<ll,vi,greater<ll>>
#define loop(i,x,y,z) for(int i=x; i<=y; i+=z)
#define loopR(i,x,y,z) for(int i=x; i>=y; i-=z)
#define all(x) begin(x), end(x)
#define allR(x) rbegin(x), rend(x)
#define watch(x) cout<<(#x)<<" is "<<x<<'\n'
#define display(v,c) for(auto x:v) cout<<x<<c;
#define endl "\n"

ll m = (ll)(1e9) + 7;

ll modPow(ll a, ll b, ll m)
{
	ll res = 1;
	a = a % m;
	while (b)
	{
		if (b & 1)
			res = ((res)%m * (a%m)) % m;
		a = ((a % m) * (a % m)) % m;
		b >>= 1;
	}
	return res % m;
}

ll solve3(ll n)
{	if (n == 1) return 1;
	if (n % 3 == 0) return modPow(3,n/3,m);
	if (n % 3 == 2) return (modPow(3, (n - 2) / 3, m) * 2) % m;
	return (modPow(3, (n - 4) / 3, m) * 4) % m;
}
int main(){
	IOS
	// do magic here
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		cout<<solve3(n)%m;
		cout<<endl;
	}
	return 0;
}