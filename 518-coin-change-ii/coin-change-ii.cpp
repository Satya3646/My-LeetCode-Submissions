class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        int n = coins.size();

        vector <unsigned long long> dp(amount+1, 0);
        dp[0] = 1; // zero sum can be achieved in 1 way.

        for(int i = 0; i < n; i++)
        {
            for(int j = coins[i]; j <= amount; j++)
            {
                dp[j] += dp[j - coins[i]];
            }
        }

        return dp[amount];
    }
};