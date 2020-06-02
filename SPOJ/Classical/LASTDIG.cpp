// https://www.spoj.com/problems/LASTDIG/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
	IOS
	ll t,a,b,ans;
	cin>>t;
	while(t--){
		cin>>a>>b;
		a=a%10;
		if(!b) cout<<1<<endl;
		else{
			b=b%4;
			if(!b) b=4;
			ans=(ll)(pow(a,b));
			cout<<ans%10<<endl;
		}
	}
	return 0;
}
