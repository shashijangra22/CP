// https://www.spoj.com/problems/PALIN/
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
#define watch(x) cout<<(#x)<<" is "<<x
#define endl "\n"

ll gcd(ll a, ll b){
	return (!b)?a:gcd(b,a%b);
}

void display(vi &v,string c){
	for(auto x:v) cout<<x<<c;
}

string add1(string x){
	bool carry=1;
	for(int i=x.size()-1; i>=0; i--){
		if(carry){
			if(x[i]=='9') x[i]='0';
			else{
				x[i]++;
				return x;
			}	
		}
		else return x;
	}
	return ((carry)?("1"+x):(x));
}

bool nines(string x){
	for(auto a:x) if(a!='9') return false;
	return true;
}

int main(){
	IOS
	ll t,mid;
	string str,left,right,ans;
	cin>>t;
	while(t--){
		cin>>str;
		if(nines(str)){
			str=add1(str);
			str[str.size()-1]++;
			cout<<str<<"\n";
			continue;
		}
		mid=str.size()/2;
		left=str.substr(0,mid);
		right=left;
		reverse(all(right));
		if(str.size()&1){ // odd length
			ans=left+str[mid]+right;
			if(ans>str) cout<<ans;
			else{
				if(str[mid]=='9'){
					string temp=add1(left+str[mid]);
					char x=temp.back();
					temp.popb();
					right=temp;
					reverse(all(right));
					cout<<temp+x+right;
				}
				else{
					ans[mid]++;
					cout<<ans;
				}
			}
		}
		else{ // even length
			ans=left+right;
			if(ans>str) cout<<ans;
			else{
				left=add1(left);
				right=left;
				reverse(all(right));
				cout<<left+right;
			}	
		}
		cout<<endl;
	}
	return 0;
}
