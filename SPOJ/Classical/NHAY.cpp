// https://www.spoj.com/problems/NHAY/
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

void rabinKarp(string &str, string &text)
{
	ll p = 31, m = 1e9 + 9, S = str.size(), T = text.size();
	ll mx = max(S, T);
	if (T < mx)
	{
		cout << endl;
		return;
	};
	vi powers(mx, 1), hashes(T + 1, 0);
	loop(i, 1, mx - 1, 1) powers[i] = (powers[i - 1] * p) % m;
	loop(i, 0, T - 1, 1) hashes[i + 1] = (hashes[i] + ((text[i] - 'a' + 1) * powers[i]) % m) % m;
	ll hashS = 0;
	loop(i, 0, S - 1, 1) hashS = (hashS + ((str[i] - 'a' + 1) * powers[i]) % m) % m;
	loop(i, 0, T - S, 1)
	{
		ll currHash = (hashes[i + S] - hashes[i] + m) % m;
		if (currHash == (hashS * powers[i]) % m)
			cout << i << endl;
	}
	return;
}

int main()
{
	IOS
    // do magic here
    ll temp;
	string str, text;
	while (cin >> temp)
	{
		cin >> str >> text;
		rabinKarp(str, text);
	}
	return 0;
}