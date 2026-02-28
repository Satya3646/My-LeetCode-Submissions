const int mod = 1e9+7;

class Solution {
public:
    int concatenatedBinary(int n)
    {
        long long ans = 0;
        int currbits = 0;
        for(int i = 1; i <= n; i++)
        {
            if((i & (i-1)) == 0)
                currbits++;
            ans = (ans << currbits) | i;
            ans %= mod;
        }
        return ans;
    }
};