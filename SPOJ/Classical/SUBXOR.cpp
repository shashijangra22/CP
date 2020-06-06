// https://www.spoj.com/submit/SUBXOR/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<ll>
#define vvi vector<vi>
#define P_Q priority_queue<ll>
#define p_q priority_queue<ll, vi, greater<ll>>
#define loop(i, x, y, z) for (int i = x; i <= y; i += z)
#define loopR(i, x, y, z) for (int i = x; i >= y; i -= z)
#define all(x) begin(x), end(x)
#define allR(x) rbegin(x), rend(x)
#define watch(x) cout << (#x) << " is " << x << '\n'
#define display(v, c) for (auto x : v) cout << x << c;
#define endl "\n"

struct BitTrie
{
	struct BitTrie *arr[2] = {NULL};
	ll count[2]={0};

	void insert(ll num)
	{
		BitTrie *root = this;
		int i = 32;
		while (i--)
		{
			int bit = (num >> i) & 1;
			if (!root->arr[bit])
				root->arr[bit] = new BitTrie();
			root->count[bit]++;
			root = root->arr[bit];
		}
	}

	int query(ll num, ll k)
	{
		// watch(num);
		ll ans = 0;
		BitTrie *root = this;
		int i = 32;
		while (root and i--)
		{
			int bit1 = (num >> i) & 1;
			int bit2 = (k >> i) & 1;
			if (bit2)
			{
				ans+=root->count[bit1];
				root = root->arr[!bit1];
			}
			else root = root->arr[bit1];
		}
		return ans;
	}
};

int main()
{
	IOS
	// do magic here
	ll t,n, k;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		vi v(n);
		for (auto &x : v) cin >> x;
		BitTrie trie;
		ll prev = 0;
		ll ans = 0;
		trie.insert(0);
		for (auto x : v)
		{
			prev = prev ^ x;
			ans += trie.query(prev, k);
			// watch(ans);
			trie.insert(prev);
		}
		cout << ans << endl;
	}
	return 0;
}