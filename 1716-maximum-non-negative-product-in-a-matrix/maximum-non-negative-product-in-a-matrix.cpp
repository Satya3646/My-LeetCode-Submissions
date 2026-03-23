const int mod = 1e9+7;

class Solution {
public:
    int maxProductPath(vector <vector <int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector <vector <long long>> maxProd(m, vector <long long> (n, 0)), minProd(m, vector <long long> (n, 0));
        maxProd[0][0] = minProd[0][0] = grid[0][0];

        for(int i = 1; i < m; i++)
            minProd[i][0] = maxProd[i][0] = maxProd[i-1][0] * grid[i][0];

        for(int i = 1; i < n; i++)
            minProd[0][i] = maxProd[0][i] = maxProd[0][i-1] * grid[0][i];

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(grid[i][j] < 0)
                {
                    maxProd[i][j] = min(minProd[i-1][j], minProd[i][j-1]) * grid[i][j];
                    minProd[i][j] = max(maxProd[i-1][j], maxProd[i][j-1]) * grid[i][j];
                }
                else
                {
                    maxProd[i][j] = max(maxProd[i-1][j], maxProd[i][j-1]) * grid[i][j];
                    minProd[i][j] = min(minProd[i-1][j], minProd[i][j-1]) * grid[i][j];
                }
            }
        }
        
        int ans = maxProd[m-1][n-1] % mod;
        return ans < 0? -1: ans;
    }
};