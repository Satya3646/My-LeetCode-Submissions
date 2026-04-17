class Solution {
public:
    int findTargetSumWays(vector <int> &nums, int target)
    {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);

        // Sum(+ve) - Sum(-ve) = target.
        // Sum(+ve) + Sum(-ve) = total.
        // Sum(-ve) = (total - target) / 2.
        // Sum(+ve) = (total + target) / 2.
        // If we find Sum(-ve) remaining will make Sum(+ve).

        if(target > total || (total - target & 1))
            return 0;

        int minus = (total - target) >> 1;
        vector <int> dp(minus+1);
        dp[0] = 1;

        for(int i = 0; i < n; i++)
        {
            for(int j = minus; j >= nums[i]; j--)
            {
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[minus];
    }
};