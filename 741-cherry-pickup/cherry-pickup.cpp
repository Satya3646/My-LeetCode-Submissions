class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid)
    {
        int n = grid.size();

        // At any point the number of steps each robo took will be equal.
        // i1,j2 & i2,j2 are positions of two robos then i1+j1 = i2+j2, hence we just need to track three of them. 
        vector <vector <vector <int>>> dp(n, vector <vector <int>> (n, vector <int> (n, -1e5)));
        dp[0][0][0] = (grid[0][0] == 1);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < n; k++)
                {
                    int x1 = i, y1 = j; // coordinate of 1st robo.
                    int x2 = k, y2 = x1 + y1 - x2; // coordinate of 2nd robo.
                    
                    if (x1 == 0 && y1 == 0 && x2 == 0)
                        continue;

                    if(y2 < 0 || y2 >= n || grid[x1][y1] == -1 || grid[x2][y2] == -1)
                        continue;

                    int prev = -1e5;
                    if (x1 > 0 && y2 > 0) 
                        prev = max(prev, dp[x1 - 1][y1][x2]);
                    if (y1 > 0 && x2 > 0) 
                        prev = max(prev, dp[x1][y1 - 1][x2 - 1]);
                    if (x1 > 0 && x2 > 0) 
                        prev = max(prev, dp[x1 - 1][y1][x2 - 1]);
                    if (y1 > 0 && y2 > 0) 
                        prev = max(prev, dp[x1][y1 - 1][x2]);
                    if(prev != -1e5)
                    {
                        dp[x1][y1][x2] = prev + (grid[x1][y1] == 1);
                        if(x1 != x2 && y1 != y2)
                            dp[x1][y1][x2] += (grid[x2][y2] == 1);
                    }
                }
            }
        }

        return max(0, dp[n-1][n-1][n-1]);
    }
};