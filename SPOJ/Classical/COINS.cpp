// https://www.spoj.com/problems/COINS/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
unordered_map<ll,ll>mp;
ll solve(ll n){
	if (mp[n]) return mp[n];
	if(n<12) return mp[n]=n;
	return mp[n]=max(n,solve(n/2)+solve(n/3)+solve(n/4));
}
int main(){
	ll n;
	while(cin>>n){
		cout<<solve(n)<<"\n";
	}
}