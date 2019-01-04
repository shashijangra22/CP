// https://www.spoj.com/problems/ONP/
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
#define loop(x,y,z) for(ll i=x; i<=y; i+=z)
#define rloop(x,y,z) for(ll i=x; i>=y; i-=z)
#define all(x) x.begin(), x.end()
#define sum(x) accumulate(all(x),0LL)
#define minE(x) *min_element(all(x))
#define maxE(x) *max_element(all(x))
#define mem(a,b) memset(a,b,sizeof(a))
#define endl "\n"
unordered_map<char,ll> prec;
string ONP(string str){
	stack<ll> st;
	string ans="";
	loop(0,str.size()-1,1){
		if(isalpha(str[i])){
			ans+=str[i];
		}
		else{
			if(str[i]=='('){
				st.push('(');
				continue;
			}
			if(str[i]==')'){
				char temp=st.top();
				while(!st.empty() && temp!='('){
					ans+=temp;
					st.pop();
					temp=st.top();
				}
				st.pop();
			}
			else{
				st.push(str[i]);
			}
		}
	}
	return ans;
}
int main(){
	IOS
	ll t;
	cin>>t;
	string str;
	prec['+']=1;
	prec['-']=2;
	prec['*']=3;
	prec['/']=4;
	prec['^']=5;
	while(t--){
		cin>>str;
		cout<<ONP(str)<<endl;
	}
	return 0;
}
