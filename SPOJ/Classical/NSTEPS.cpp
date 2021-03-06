// https://www.spoj.com/problems/NSTEPS/
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
string solve(ll x, ll y){
	if(x==1 && y==1) return "1";
	if(x==0 && y==0) return "0";
	if(x==y || x-y==2) return to_string(x+y - x%2);
	return "No Number";
}
int main(){
	IOS
	ll t,x,y;
	cin>>t;
	while(t--){
		cin>>x>>y;
		cout<<solve(x,y)<<endl;
	}
	return 0;
}
