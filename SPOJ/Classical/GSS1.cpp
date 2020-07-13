// https://www.spoj.com/problems/GSS1/
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

struct item{
    ll sum,seg,pref,suff;
};

struct SegTree
{
	vector<item> tree;
	ll n;

    item func(item &a, item &b){
        item temp;
        temp.sum = a.sum + b.sum;
        temp.seg = max(a.seg,max(b.seg,a.suff + b.pref));
        temp.pref = max(a.pref,a.sum + b.pref);
        temp.suff = max(b.suff, b.sum + a.suff);
        return temp;
    }

    item single(ll val){
        item temp;
        temp.sum = val;
        temp.pref = (val > 0)?val:0;
        temp.suff = (val > 0)?val:0;
        temp.seg = (val > 0)?val:0;
        return temp;
    }

	SegTree(vi &arr, ll sz)
	{
		n = sz;
		tree.resize(2 * n);
		loop(i, 0, n - 1, 1) tree[i + n] = single(arr[i]);
		loopR(i, n - 1, 1, 1) tree[i] = func(tree[2*i],tree[2*i + 1]);
	}

	item query(ll l, ll r)
	{ // range [l,r) index wise
		l += n;
		r += n;
        r++;
		item sum1 = {0,0,0,0};
        item sum2 = {0,0,0,0};
		while (l < r)
		{
			if (l & 1) sum1 = func(sum1,tree[l++]);
			if (r & 1) sum2 = func(tree[--r],sum2);
			l >>= 1;
			r >>= 1;
		}
		return func(sum1,sum2);
	}
};

int main(){
    IOS
    // do magic here
    ll n,q,l,r;
    cin>>n;
    vi v(n);
    for(auto &x:v) cin>>x;

    SegTree tree(v,n);

    cin>>q;
    while(q--){
        cin>>l>>r;
        cout<<tree.query(l-1,r-1).seg<<endl;
    }
    return 0;
}