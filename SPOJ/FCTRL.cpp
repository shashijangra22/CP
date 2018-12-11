// https://www.spoj.com/problems/FCTRL/
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
#define all(x) x.begin(), x.end()
#define i_to_j(x,i,j) x.begin()+i, x.begin()+j
#define mem(a,b) memset(a,b,sizeof(a))
#define endl "\n"
ll solve(ll n){
	ll ans=0;
	while(n)
		ans+=(n/=5);
	return ans;
}
int main(){
	ll t,n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<solve(n)<<endl;
	}
}