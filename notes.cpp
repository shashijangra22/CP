// min path between 2 points x1,y1 & x2,y2

max(abs(x1-x2),abs(y1-y2));

// max sum contiguous sub array (Kadane's Algorithm)

t=INT_MIN, sum=0;
for(auto x:v){		// v is a vector
	t=max(x,t+x); 	// either that element is maximum or is end of an array that's sum is max
	sum=max(sum,t); 	// calculating max sum in a loop
}
return sum

// max product in contiguous sub array
// find that negative sign to which either left or right part is ans
left=1,right=n
leftprod=v[left],rightProd=v[right]
ans=INT_MIN
while(left<n){
	leftprod*=v[left]
	rightProd*=v[right]
	ans=max(ans,leftprod,rightProd)
	left++;
	right--;
}
return ans

// starting and ending index in Kadane's Algorithm
// NOTE: if all A[i]<0 then range is index of max_element(A)
t=0, sum=0;
for(int i=0; i<A.size(); i++){
	t+=A[i];
	if(t>sum){
		sum=t;
		range={s,i};
	}
	if(t<0){
		t=0;
		s=i+1;
	}
}

return {sum,range};

// trailing zeroes in n!

while(n) ans+=(n/=5);
return ans;

// duplicate element if range(1,n) and size is n+1

slow=fast=0;
while ((slow=A[slow])!=(fast=A[A[fast]]));
fast=0;
while ((slow=A[slow])!=(fast=A[fast]));
return slow;

// merge an interval in n disjoint intervals

// key points: for any 2 intervals a-b & c-d
if (max(a,c)>min(b,d)) // disjoint intervals
else // overlaps

// if intervals from i to j overlaps with a given interval x
//  we can replace all of them (merge) with

min(A[i].start,x.start),max(A[j].end,x.end);

// merge all overlapping intervals (NLogN)

sort(A);	// sort A on start time
t=A[0];
ans=[];
loop(1,N)
	if(A[i].start<=t.end)	// overlapping
		t={min(A[i].start,t.start),max(A[i].end,t.end)};
	else
		ans.pb(t);
		t=A[i];
ans.pb(t);
return ans;

// hotel bookings possible in NlogN with k hotels

for(auto x:ArrivalDays) v.pb({x,1});
for(auto x:DepartureDays) v.pb({x,0}); // 0 on departure so that clashes can be resolved
x=0;
for(auto i:v)
	if(i.second) x++;
	else x--;
	if(x>K) return false;
return true;

// traversing anti-diagonals

loop(0,A.size())
	loop(0,A.size())
		ans[x+y].pb(A[x][y]);
return ans;

// inplace next_permutation(A)

rloop(A.size(),1)
	if(A[x-1] < A[x])	// decreasing(affected) suffix breakpoint x
		break;
if(x)	// x=0 means descending vector
	rloop(A.size(),x)
		if(A[i]>A[x-1])	// finding first A[i]>A[x-1]
			swap(A[i],A[x-1]); // to swap with
			break;
reverse(A.begin()+x,A.end());	// reversing the affected suffix

// majority element with freq N/K in given vector V

// fact: at most K-1 elements can be in solution
map<int,int>bucket;
vector<int>ans;
for(auto x:V){
    if(bucket[x]) bucket[x]++;
    else{
        if(bucket.size()<k-1) bucket[x]++;
        else for(auto i:bucket) i.second--;
    }
}
for(auto item:bucket){
    item.second=0;
    for(auto x:V){
        if(item.first==x) item.second++;
    }
    if(item.second>V.size()/k) ans.push_back(item.first);
}
return ans;

// majority element for N/2

a,c=0
for(auto x:A){
	if(!c) a=x;
	c+=(a==x)?1:-1;
}
return a

// all individually linearly dependent vectors reduces to 
// same vector when divided by GCD of their elements

// next palindrome
if(allNines(str)) return str+2;
left=str[:mid]
right=reverse(left);	
if (len(str) is even){
	ans=left+right
	if (ans>str) return ans
	return (addone(left) + reverse(addone(left)))
}
else{
	ans=left+str[mid]+right
	if(ans>str) return ans
	if(str[mid]=='9'){
		x=addone(left+str[mid])
		return x[:-1]+x[-1]+reverse(x[:-1])
	}
	else{
		return left + ++str[mid] + right
	}
}

ll gcd(ll a, ll b){
	return (!b)?a:gcd(b,a%b);
}

// factors of a number N in sqrt(N)
vi factors;
for(ll x=2; x<=sqrt(N); x++) if (N%x==0) factors.pb(x), while(N%x==0) N/=x;
if(N>2) factors.pb(N);

// divisors upto number N as Div[x]?
vvi Div(N);
loop(i,1,N,1) loop(j,i,N,i) Div[j].pb(i);

// prime sieve upto MAX
vector<bool> P(MAX,1);
for(ll i=2,i<=sqrt(MAX),i++) if (P[i]) for(ll j=i+i,j<=MAX,j+=i) P[j]=0;


// phi(1..N) in sqrt(N)

loop(i,1,N,1) phi[i]=i;
loop(i,2,N,1){
	if (phi[i]==i){ // isPrime
		phi[i]--;
		loop(j,i+i,N,i) phi[j]=(phi[j]/i)*(i-1);
	}
}

// DSU

vector<ll> parent(n); // initially self
vector<ll> sizes(n,1); // initially 1
 
ll FIND(ll a){ return (a==parent[a])?a:parent[a]=FIND(parent[a]); }

bool CHECK(ll a, ll b) { return FIND(a)==FIND(b); }

void JOIN(ll a, ll b) { parent[FIND(b)]=FIND(a); }

void UNION(ll a, ll b){ // union by size
	ll xRoot=FIND(a),yRoot=FIND(b);
	if(xRoot==yRoot) return;
	if(sizes[xRoot]<sizes[yRoot]) swap(xRoot,yRoot);
	parent[yRoot]=xRoot;
	sizes[xRoot]+=sizes[yRoot];
}

// segment tree

const int MAX_N = (int)1e5 + 777;  // limit for array size
ll TREE[2 * MAX_N];

void build() { loopR(i,n-1,1,1) TREE[i]=TREE[i<<1] + TREE[i<<1|1]; }

void update(ll x,ll p) {
	p--;
	p+=n;
	TREE[p]=x;
	for (;p > 0; p >>= 1) TREE[p>>1] = TREE[p] + TREE[p^1];
}

ll query(ll l, ll r){
	ll ans=0;
	--l,--r;
	l+=n,r+=n;
	r++;
	while(l < r) {
	    if (l&1) ans+=TREE[l++];
		if (r&1) ans+=TREE[--r];
		l>>=1;
		r>>=1;
	}
	return ans;
}