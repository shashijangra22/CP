// Z Function
vi computeZ(string str,ll n){
	vi Z(n,0);
	ll l=0,r=0;
	loop(i,1,n-1,1){
		if (i<=r) Z[i]=min(Z[i-l],r-i+1);
		while (i+Z[i] < n and str[Z[i]] == str[i+Z[i]]) ++Z[i];
		if (i+Z[i]-1 > r){
			l=i;
			r=i+Z[i]-1;
		}
	}
	return Z;
}