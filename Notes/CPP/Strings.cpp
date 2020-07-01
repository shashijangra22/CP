// Z Function
vi computeZ(string str, ll n)
{
	vi Z(n, 0);
	ll l = 0, r = 0;
	loop(i, 1, n - 1, 1)
	{
		if (i <= r)
			Z[i] = min(Z[i - l], r - i + 1);
		while (i + Z[i] < n and str[Z[i]] == str[i + Z[i]])
			++Z[i];
		if (i + Z[i] - 1 > r)
		{
			l = i;
			r = i + Z[i] - 1;
		}
	}
	return Z;
}

// hashing
vi rabinKarp(string &str, string &text)
{
	ll p = 31, m = 1e9 + 9, S = str.size(), T = text.size();
	ll mx = max(S, T);
	if (T < mx)
		return {};
	vi powers(mx, 1), hashes(T + 1, 0);
	loop(i, 1, mx - 1, 1) powers[i] = (powers[i - 1] * p) % m;
	loop(i, 0, T - 1, 1) hashes[i + 1] = (hashes[i] + ((text[i] - 'a' + 1) * powers[i]) % m) % m;
	ll hashS = 0;
	loop(i, 0, S - 1, 1) hashS = (hashS + ((str[i] - 'a' + 1) * powers[i]) % m) % m;
	vi occ;
	loop(i, 0, T - S, 1)
	{
		ll currHash = (hashes[i + S] - hashes[i] + m) % m;
		if (currHash == (hashS * powers[i]) % m)
			occ.push_back(i);
	}
	return occ;
}
// suffix Array
vector<int> suffixArray(string &s)
{
	s += '$';
	int n = s.size();
	// k = 0
	vector<int> p(n), c(n);
	vector<pair<int, int>> a(n);
	loop(i, 0, n - 1, 1) a[i] = {s[i], i};
	sort(all(a));
	loop(i, 0, n - 1, 1) p[i] = a[i].second;

	c[p[0]] = 0;
	loop(i, 1, n - 1, 1) c[p[i]] = c[p[i - 1]] + (a[i].first != a[i - 1].first);

	int k = 0;
	while ((1 << k) < n)
	{ // k => k + 1
		vector<pair<pair<int, int>, int>> a(n);
		loop(i, 0, n - 1, 1) a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
		sort(all(a));
		loop(i, 0, n - 1, 1) p[i] = a[i].second;
		c[p[0]] = 0;
		loop(i, 1, n - 1, 1) c[p[i]] = c[p[i - 1]] + (a[i].first != a[i - 1].first);
		k++;
	}
	return p;
}