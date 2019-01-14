// https://www.spoj.com/problems/CANDY/
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
	ll n;
	vi v;
	while(1){
		cin>>n;
		if(n==-1) break;
		v.clear();
		v.resize(n);
		loop(0,n-1,1) cin>>v[i];
		ll temp=sum(v);
		if(temp%n == 0){
			ll c=0,x=temp/n;
			loop(0,n-1,1){
				if(v[i]<x){
					c+=(x-v[i]);
				}
			}
			cout<<c<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
	return 0;
}
