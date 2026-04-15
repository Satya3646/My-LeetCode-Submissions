class Solution {
public:
    int coinChange(vector <int> &coins, int amount)
    {
        int n = coins.size();

        vector <int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= amount; i++)
        {
            int minCoins = INT_MAX;
            for(int j = 0; j < n; j++)
            {
                if(coins[j] <= i)
                    minCoins = min(minCoins, dp[i - coins[j]]);
            }
            if(minCoins != INT_MAX)
                dp[i] = 1 + minCoins;
        }

        return dp[amount] != INT_MAX? dp[amount]: -1;
    }
};