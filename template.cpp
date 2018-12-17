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
#define loop(x,y) for(ll i=x; i<=y; i++)
#define rloop(x,y) for(ll i=x; i>=y; i--)
#define all(x) x.begin(), x.end()
#define sum(x) accumulate(all(x),0LL)
#define minE(x) *min_element(all(x))
#define maxE(x) *max_element(all(x))
#define mem(a,b) memset(a,b,sizeof(a))
#define endl "\n"
int main(){
	IOS
	ll n,temp;
	cin>>n;
	vi arr;
	loop(0,n-1){
		cin>>temp;
		arr.pb(n-temp);
	}
	int flag=0;
	loop(1,n-1){
		if(arr[i]==arr[i-1]) continue;
		else {
			flag=1;
			break;
		}
	}
	if(flag){
		cout<<"Possible\n";
		loop(1,n){
			cout<<1<<" ";
		}
		return 0;
	}
	map<ll> freq;
	for(auto x:arr){
		freq[x]++;
	}
	for(auto x:freq){
		if(x.first!=x.second){
			flag=1;
			break;
		}
	}
	if(flag) cout<<"Impossible";
	else{
		cout<<"Possible\n";
		for(auto x:freq){
			loop(1,x.second){
				cout<<i<<" ";
			}
		}
	}
	return 0;
}
