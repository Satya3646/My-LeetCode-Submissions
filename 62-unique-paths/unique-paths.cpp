class Solution {
public:
    long long nCr(int n, int r)
    {
        long long ans = 1;
        for(int i = 1; i <= r; i++)
            ans = (ans * (n - r + i)) / i;
        
        return ans;
    }

    int uniquePaths(int m, int n)
    {
        // vector <vector <int>> dp(m, vector <int> (n, 1));

        // for(int i = 1; i < m; i++)
        //     for(int j = 1; j < n; j++)
        //         dp[i][j] = dp[i-1][j] + dp[i][j-1];

        // return dp[m-1][n-1];

        return nCr(m + n - 2, m - 1);
    }
};