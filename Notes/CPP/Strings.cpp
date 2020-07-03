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

struct suffixArray
{
	vi p, c, lcp;
	string str;
	vector<pair<pll, ll>> a;
	int n = 0, k = 0;
	suffixArray(string &s)
	{
		str = s + '$';
		n = str.size();
		p.resize(n);	// suffix array
		c.resize(n); 	// equivalence classes
		a.resize(n);	// array to be sorted based on c
        lcp.resize(n);  // array to store LCP of adjacent suffixes
	}

	void radix_sort(int ele)
	{
		vi pos(n),cnt(n);
		for (auto x : a) if (ele) cnt[x.first.second]++; else cnt[x.first.first]++;
		pos[0] = 0;
		loop(i, 1, n - 1, 1) pos[i] = pos[i - 1] + cnt[i - 1];
		vector<pair<pll, ll>> a_new(n);
		for (auto x : a)
		{
			int i = (ele) ? x.first.second : x.first.first;
			a_new[pos[i]] = x;
			pos[i]++;
		}
		a = a_new;
	}

	void assignClasses()
	{
		loop(i, 0, n - 1, 1) p[i] = a[i].second;
		c[p[0]] = 0;
		loop(i, 1, n - 1, 1) c[p[i]] = c[p[i - 1]] + (a[i].first != a[i - 1].first);
	}

	void buildSuffixArray()
	{
		loop(i, 0, n - 1, 1) a[i] = {{str[i], str[i]}, i};
		sort(all(a)); // k = 0
		assignClasses();
		while ((1 << k) < n) // k -> k + 1
		{
			loop(i, 0, n - 1, 1) a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
			radix_sort(1);
			radix_sort(0);
			// sort(all(a));
			assignClasses();
			k++;
		}
	}

    void buildLCP(){
        k = 0;
        loop(i,0,n-2,1){
            ll pos_i = c[i];
            ll j = p[pos_i - 1];
            while (str[i + k]==str[j + k]) k++;
            lcp[pos_i] = k;
            k = max(k-1,0);
        }
    }

};