// https://www.spoj.com/problems/TOANDFRO/
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
	ll temp;
	string str,ans;
	while(1){
		cin>>temp;
		if(!temp) break;
		cin>>str;
		ans="";
		ll x=2*temp;
		ll a=x-1;
		ll b=1;
		ll flag=0;
		ll t;
		loop(0,temp-1,1){
			t=i;
			flag=0;
			while(t<str.size()){
				ans+=str[t];
				if(!flag){
					t+=a;
				}
				else{
					t+=b;
				}
				flag^=1;
			}
			a-=2;
			b+=2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
