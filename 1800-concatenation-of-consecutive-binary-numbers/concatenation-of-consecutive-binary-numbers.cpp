const int mod = 1e9+7;

class Solution {
public:
    int concatenatedBinary(int n)
    {
        long long ans = 0; // use long since it has 64 bits.
        int currbits = 0; // keeps track of the number of bits current integer has.

        for(int i = 1; i <= n; i++)
        {
            // The number of bits changes only when current integer is a power of 2.
            if((i & (i-1)) == 0)
                currbits++;
            
            // Left shift the answer by number of bits in current integer and OR with it.
            ans = (ans << currbits) | i;
            ans %= mod;
        }
        
        return ans;
    }
};