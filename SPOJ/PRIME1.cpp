// https://www.spoj.com/problems/PRIME1/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool isPrime(ll x){
	ll root=(ll)sqrt(x);
	for(ll i=2; i<=root; i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}
int main(){
	ll t,l,r;
	cin>>t;
	while(t--){
		cin>>l>>r;
		for(ll i=l; i<=r; i++){
			if(i!=1 && isPrime(i)){
				cout<<i<<"\n";
			}
		}
		cout<<"\n";
	}
	return 0;
}