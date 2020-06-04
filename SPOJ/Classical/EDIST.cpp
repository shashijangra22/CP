// # https://www.spoj.com/problems/EDIST/
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
#define MAX 2005
ll dp[MAX+1][MAX+1];

int main(){
	IOS
	// do magic here
	ll t;
	cin>>t;
	string A,B;
	while(t--){
		loop(c,0,MAX,1) dp[0][c]=c;
		loop(r,0,MAX,1) dp[r][0]=r;
		cin>>A>>B;
		loop(i,1,A.size(),1){
			loop(j,1,B.size(),1){
				if(A[i-1]==B[j-1]) dp[i][j]=dp[i-1][j-1];
				else dp[i][j] = min(1 + dp[i-1][j-1],min(1 + dp[i-1][j], 1 + dp[i][j-1]));
			}
		}
		cout<<dp[A.size()][B.size()]<<endl;
	}
	return 0;
}