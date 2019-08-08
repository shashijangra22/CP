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

while(n)
    ans+=(n/=5);
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

