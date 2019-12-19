// https://code.google.com/codejam/contest/2924486/dashboard#s=p2
#include<bits/stdc++.h>
using namespace std;

int main() {
	
    priority_queue<int> even;
    priority_queue<int,vector<int>,greater<int>> odd;
    int t,n;
    cin>>t;
    for(int cass=1; cass<=t; cass++){
        cin>>n;
        vector<int> v(n);
        cout<<"Case #"<<cass<<": ";
        for(int j=0; j<n; j++) cin>>v[j];
        for(auto x:v){
            if(x&1) odd.push(x);
            else even.push(x);
        }
        for(auto x:v){
            if(x&1){
                cout<<odd.top()<<" ";
                odd.pop();
            }
            else{
                cout<<even.top()<<" ";
                even.pop();
            }
        }
        cout<<endl;
    }

	return 0;
	
}