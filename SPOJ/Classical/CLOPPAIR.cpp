// https://www.spoj.com/problems/CLOPPAIR/
#include<bits/stdc++.h>
using namespace std;
// include <ext/pb_ds/assoc_container.hpp>
// include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
// typedef tree <ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<ll>
#define vvi vector<vi>
#define P_Q priority_queue<ll>
#define p_q priority_queue<ll,vi,greater<ll>>
#define pb push_back
#define popb pop_back
#define ub upper_bound
#define lb lower_bound
#define loop(i,x,y,z) for(int i=x; i<=y; i+=z)
#define loopR(i,x,y,z) for(int i=x; i>=y; i-=z)
#define all(x) begin(x), end(x)
#define allR(x) rbegin(x), rend(x)
#define sum(x) accumulate(all(x),0LL)
#define minE(x) *min_element(all(x))
#define maxE(x) *max_element(all(x))
#define watch(x) cout<<(#x)<<" is "<<x<<'\n'
#define display(v,c) for(auto x:v) cout<<x<<c;
#define setbits(x) __builtin_popcount(x)
#define ctoi(x) (int)((x)-'a')
#define endl "\n"

int pt1,pt2;
double best=1000000000;
map<pii,int> ID;

double closestPair(vector<pii> &points){
	int n = points.size();
    sort(all(points));
    set<pii> box;

	int j=0;
	loop(i,0,n-1,1){
		int d=ceil(best);

		while( abs(points[i].first - points[j].first) >= best){
			box.erase({points[j].second,points[j].first});
			j++;
		}

		auto low = box.lb({points[i].second - d, points[i].first});
		auto high = box.ub({points[i].second + d, points[i].first});

		while(low!=high){
			int dx = points[i].first - low->second;
			int dy = points[i].second - low->first;
			double temp = sqrt(dx*dx + dy*dy);
			if (temp < best){
				best=temp;
				pt1=ID[points[i]];
				pt2=ID[{low->second,low->first}];
			}
			low++;
		}
		box.insert({points[i].second,points[i].first});
	}
	return best;
}

int main(){
	IOS
	// do magic here
	int n,x,y;
	cin>>n;
	vector<pii> points;
	loop(i,0,n-1,1){
		cin>>x>>y;
		points.pb({x,y});
		ID[{x,y}]=i;
	}
	double ans=closestPair(points);
	cout<<min(pt1,pt2)<<' '<<max(pt1,pt2);
	printf(" %0.6f", ans);
	return 0;
}
