class Solution {
public:
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, vector <vector <int>> &dp)
    {
        if(i == nums1.size()) // end of nums1 so cant choose further.
        {
            if(j == 0) // none from nums2 was choosen so return INT_MIN to make this path invalid, no pairs were selected.
                return INT_MIN;
            return 0; // 0 since no more pairs can be formed since nums1 is exhausted.
        }
        if(j == nums2.size()) // end of nums2, none left to pick so return 0.
            return 0;

        if(dp[i][j] != -1) // if already computed the return directly.
            return dp[i][j];
        
        int skip = solve(i+1, j, nums1, nums2, dp); // skip element at i.

        // pick element at i and find product with different possibilities from j to end.
        int pick = INT_MIN;
        for(int k = j; k < nums2.size(); k++)
            pick = max(pick, nums1[i] * nums2[k] + solve(i+1, k+1, nums1, nums2, dp));

        dp[i][j] = max(pick, skip); // update dp.
        return dp[i][j];
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector <vector <int>> dp(n1, vector <int> (n2, -1));
        return solve(0, 0, nums1, nums2, dp);
    }
};