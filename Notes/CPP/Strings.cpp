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

vi rabinKarp(string &str, string &text)
{
	ll p = 31, m = 1e9 + 9, S = str.size(), T = text.size();
	ll mx = max(S, T);
	if (T < mx) return {};
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