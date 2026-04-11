class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins)
    {
        int m = coins.size();
        int n = coins[0].size();

        vector <vector <vector <int>>> dp(m, vector <vector <int>> (n, vector <int> (3, 0)));
        dp[0][0][0] = coins[0][0];
        dp[0][0][1] = max(0, coins[0][0]);
        dp[0][0][2] = max(0, coins[0][0]);

        // current cell (0, j) can only be reached from (0, j-1).
        for(int j = 1; j < n; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                int val = dp[0][j-1][k] + coins[0][j];
                if(coins[0][j] < 0 && k > 0)
                    val = max(val, dp[0][j-1][k-1]);
                dp[0][j][k] = val;
            }
        }

        // current cell (i, 0) can only be reached from (i-1, 0).
        for(int i = 1; i < m; i++)
        {
            for(int k = 0; k < 3; k++)
            {
                int val = dp[i-1][0][k] + coins[i][0];
                if(coins[i][0] < 0 && k > 0)
                    val = max(val, dp[i-1][0][k-1]);
                dp[i][0][k] = val;
            }
        }

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                for(int k = 0; k < 3; k++)
                {
                    dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k]) + coins[i][j];
                    if(coins[i][j] < 0 && k > 0)
                        dp[i][j][k] = max({dp[i][j][k], dp[i-1][j][k-1], dp[i][j-1][k-1]});
                }
            }
        }

        return dp[m-1][n-1][2];
    }
};