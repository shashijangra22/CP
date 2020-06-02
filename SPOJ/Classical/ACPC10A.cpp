// https://www.spoj.com/problems/ACPC10A/
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
ll solve(ll x){
	return (x*(x+1)*(2*x+1))/6;
}
int main(){
	IOS
	ll a,b,c;
	while(1){
		cin>>a>>b>>c;
		if(!a && !b && !c) break;
		if(c-b == b-a) cout<<"AP "<<2*c - b<<endl;
		else cout<<"GP "<<c*(c/b)<<endl;		
	}
	return 0;
}
