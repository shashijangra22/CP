// https://www.spoj.com/problems/ACODE/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<ll>
#define vvi vector<vi>
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
#define watch(x) cout<<(#x)<<" is "<<x<<"\n";
#define endl "\n"

ll gcd(ll a, ll b){
	return (!b)?a:gcd(b,a%b);
}

void display(vi &v,string c){
	for(auto x:v) cout<<x<<c;
}

bool isValid(char a, char b){
	if (a=='1') return true;
	if (a=='2' and b<='6') return true;
	return false;
}

int main(){
	IOS
	ll a,b,prev1,prev2,curr;
	string input;
	while(1){
		cin>>input;
		prev1=1;
		prev2=((input[1]!='0')+isValid(input[0],input[1]));
		loop(2,input.size()-1,1){
			curr=((input[i]!='0')?prev2:0) + ((isValid(input[i-1],input[i]))?prev1:0);
			prev1=prev2;
			prev2=curr;
		}
		if(input[0]=='0') break;
		cout<<curr<<"\n";
	}
	return 0;
}
