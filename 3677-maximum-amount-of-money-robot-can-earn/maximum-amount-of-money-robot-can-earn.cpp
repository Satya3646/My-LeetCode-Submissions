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

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0)
                    continue;
                
                for(int k = 0; k < 3; k++)
                {
                    int val = -1e8;
                    if(i > 0)
                    {
                        val = max(val, dp[i-1][j][k] + coins[i][j]); // no neutralization.
                        if(coins[i][j] < 0 && k > 0) // neutralization.
                            val = max(val, dp[i-1][j][k-1]);
                    }
                    if(j > 0)
                    {
                        val = max(val, dp[i][j-1][k] + coins[i][j]); // no neutralization.
                        if(coins[i][j] < 0 && k > 0) // neutralization.
                            val = max(val, dp[i][j-1][k-1]);
                    }
                    dp[i][j][k] = val;
                }
            }
        }
        return dp[m-1][n-1][2];
    }
};