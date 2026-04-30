class Solution {
public:
    int maxPathScore(vector <vector <int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[i][j][k] = max score to reach i, j with cost limited to k.
        vector <vector <vector <int>>> dp(m, vector <vector <int>> (n, vector <int> (k+1, INT_MIN)));
        dp[0][0][0] = 0;

        for(int i = 1; i < m; i++)
        {
            for(int cost = 0; cost <= k; cost++)
            {
                if(grid[i][0] == 0)
                    dp[i][0][cost] = dp[i-1][0][cost];
                else if(cost > 0 && dp[i-1][0][cost - 1] != INT_MIN)
                    dp[i][0][cost] = dp[i-1][0][cost - 1] + grid[i][0];
            }
        }

        for(int j = 1; j < n; j++)
        {
            for(int cost = 0; cost <= k; cost++)
            {
                if(grid[0][j] == 0)
                    dp[0][j][cost] = dp[0][j-1][cost];
                else if(cost > 0 && dp[0][j-1][cost - 1] != INT_MIN)
                    dp[0][j][cost] = dp[0][j-1][cost - 1] + grid[0][j];
            }
        }

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(i == 0 && j == 0)
                    continue;
                
                for(int cost = 0; cost <= k; cost++)
                {
                    int val = INT_MIN;
                    if(grid[i][j] == 0)
                    {
                        val = max(val, dp[i-1][j][cost]);
                        val = max(val, dp[i][j-1][cost]);
                    }
                    else if(cost > 0)
                    {
                        val = max(val, dp[i-1][j][cost - 1]);
                        val = max(val, dp[i][j-1][cost - 1]);
                    }
                    
                    if(val != INT_MIN)
                        dp[i][j][cost] = val + grid[i][j];
                }
            }
        }
        
        int ans = *max_element(dp[m-1][n-1].begin(), dp[m-1][n-1].end());
        return ans == INT_MIN? -1: ans;
    }
};