// min path between 2 points x1,y1 & x2,y2

max(abs(x1-x2),abs(y1-y2));

// max sum contiguous sub array (Kadane's Algorithm)

t=INT_MIN, sum=0;
for(auto x:v){		// v is a vector
	t=max(x,t+x); 	// either that element is maximum or is end of an array that's sum is max
	sum=max(sum,t); 	// calculating max sum in a loop
}

return sum;

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
    ans+=(n/=5)
return ans

// duplicate element if range(1,n) and size is n+1

slow=fast=0
while ((slow=A[slow])!=(fast=A[A[fast]]));
fast=0
while ((slow=A[slow])!=(fast=A[fast]));
return slow

// merge an interval in n disjoint intervals

// key points: for any 2 intervals a-b & c-d
if (max(a,c)>min(b,d)) // disjoint intervals
else // overlaps

// if intervals from i to j overlaps with a given interval x
//  we can replace all of them (merge) with

min(A[i].start,x.start),max(A[j].end,x.end)

// merge all overlapping intervals (NLogN)

sort(A)	// sort A on start time
t=A[0]
ans=[]
for i = 1 to N
	if(A[i].start<=t.end)	// overlapping
		t={min(A[i].start,t.start),max(A[i].end,t.end)}
	else
		ans.pb(t)
		t=A[i]
ans.pb(t)
return ans
