// count of 
__builtin_popcount(n) // set bits
ctz() // trailing zeros
clz() // leading zeros

// is Power Of 2?
x and (x & x-1)

// rightmost set bit
x ^ (x & (x-1))

// set ith bit
x | 1<<i

// unset ith bit
x & ~(1<<i)

// set ith bit to v (also for signed numbers)
unset(i)
x | v<<i

// list of set bits in numbers upto N
dp[i]=(i&1)?dp[i-1]+1:dp[i/2]

// XOR of x,x+1,x+2,x+3 always gives 0
// so XOR of 1 to N is always N+1 or N or 1 or 0