// https://www.spoj.com/problems/INVCNT/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<ll>
#define vvi vector<vi>
#define P_Q priority_queue<ll>
#define p_q priority_queue<ll,vi,greater<ll>>
#define loop(i,x,y,z) for(int i=x; i<=y; i+=z)
#define loopR(i,x,y,z) for(int i=x; i>=y; i-=z)
#define all(x) begin(x), end(x)
#define allR(x) rbegin(x), rend(x)
#define watch(x) cout<<(#x)<<" is "<<x<<'\n'
#define display(v,c) for(auto x:v) cout<<x<<c;
#define endl "\n"

struct BIT{
	int n;
	vector<int> tree;

	BIT(int sz){
		n = sz;
		tree.resize(n+1);
	}
	void update(int idx,int val){
		while(idx <= n){
			tree[idx]+=val;
			idx += (idx & -idx);
		}
	}
	int query(int idx){
		int sum = 0;
		while(idx){
			sum += tree[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}
};

int MAX = int(1e7 + 1);

int main(){
	IOS
	// do magic here
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		ll ans=0;
		BIT bit(MAX);
		vector<int> v(n);
		for(auto &x:v) cin>>x;
		loopR(i,n-1,0,1){
			bit.update(v[i],1);
			ans+=bit.query(v[i]-1);
		}
		cout<<ans<<endl;
	}
	return 0;
}