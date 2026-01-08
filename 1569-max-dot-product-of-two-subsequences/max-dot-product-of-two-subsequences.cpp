class Solution {
public:
    int maxDotProduct(vector <int> &nums1, vector <int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector <vector <int>> dp(n1+1, vector <int> (n2+1, INT_MIN));

        for(int i = 1; i <= n1; i++)
        {
            for(int j = 1; j <= n2; j++)
            {
                int prod = nums1[i-1] * nums2[j-1]; // product of current picks (i, j).
                int take = INT_MIN;
                if(i > 1 && j > 1) // get the "prev max" + "current prod"
                    take = prod + dp[i-1][j-1];

                /* take the largest among prod, 
                   sum by taking current pair, 
                   not pick current i, not picking current j. */
                dp[i][j] = max({prod, take, dp[i-1][j], dp[i][j-1]});
            }
        }

        return dp[n1][n2];
    }
};