class Solution {
public:
    int minFallingPathSum(vector <vector <int>> &matrix)
    {
        int n = matrix.size();
        
        vector <vector <int>> dp(n, vector <int> (n, INT_MAX));
        dp[0] = matrix[0]; // first row is the starting point.

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // reach current cell from top cell.
                dp[i][j] = min(dp[i][j], dp[i-1][j] + matrix[i][j]);

                // left diagonally above cell.
                if(j > 0)
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + matrix[i][j]);

                // right diagonally above cell.
                if(j < n-1)
                    dp[i][j] = min(dp[i][j], dp[i-1][j+1] + matrix[i][j]);
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};