// https://www.spoj.com/problems/BYTESM2/
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

int main(){
	IOS
	// do magic here
	ll t,h,w,c;
	cin>>t;
	while(t--){
		cin>>h>>w;
        vvi grid(h+2,vi (w+2,0));
        loop(i,1,h,1) loop(j,1,w,1){
            cin>>grid[i][j];
            if (i!=1) grid[i][j] += *max_element(grid[i-1].begin()+j-1,grid[i-1].begin()+j+2);
        }
        cout<<*max_element(all(grid[h]))<<endl;
	}
	return 0;
}