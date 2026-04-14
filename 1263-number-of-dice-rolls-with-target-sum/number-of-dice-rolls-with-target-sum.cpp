const int mod = 1e9+7;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target)
    {
        vector <int> dp(target+1, 0);
        dp[0] = 1; // sum zero can be obtained using zero dice in 1 way.
        
        for(int i = 1; i <= n; i++) // number of dice used.
        {
            for(int j = target; j >= 0; j--) // sum using i dice.
            {
                int ways = 0;
                for(int last = 1; last <= k; last++) // previous rolls.
                {
                    if(j >= last)
                        ways = (ways + dp[j - last]) % mod;

                    dp[j] = ways;
                }
            }
        }

        return dp[target];
    }
};