// binary exponentiation (a to the power p) mod m
ll modPow(a,p,m){
	ll res=1
	while(p){
		if (p&1) res=(res*a)%m;
		a=(a*a)%m;
		p>>=1;
	}
	return res%m;
}

// phi(1..N) in sqrt(N) [integers coprime with N][Euler Totient]
// phi[i] is only prime (i.e 2) for i=3,4,6
loop(i,1,N,1) phi[i]=i;
loop(i,2,N,1){
	if (phi[i]==i){ // isPrime
		phi[i]--;
		loop(j,i+i,N,i) phi[j]-=(phi[j]/i)
	}
}

// Fast GCD
ll gcd(ll a, ll b){
	return (!b)?a:gcd(b,a%b);
}

// factors of a number N in sqrt(N)
vector<ll> factors;
for(ll x=2; x*x<=N; x++) if (N%x==0) factors.pb(x), while(N%x==0) N/=x;
if(N>2) factors.pb(N);

// divisors upto number N as Div[x]?
vector<vector<ll>> Div(N);
loop(i,1,N,1) loop(j,i,N,i) Div[j].pb(i);

// prime sieve upto MAX works upto 10**8
vector<bool> P(MAX,1);
for(ll i=2,i*i<=MAX,i++) if (P[i]) loop(j,i+i,MAX,i) P[j]=0;

if (max(a,c)>min(b,d)) // disjoint intervals for (a,b) and (c,d)
else // overlaps

// trailing zeroes in n!
while(n){
	ans+=(n/5);
	n/=5;
}
return ans;

// min and max of (a,b) without using relational operators
max=(a+b+abs(a-b))/2
min=(a+b-abs(a-b))/2

// min path between 2 points x1,y1 & x2,y2
max(abs(x1-x2),abs(y1-y2));
