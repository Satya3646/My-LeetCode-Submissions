class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if(total & 1)
            return false;
        
        int n = nums.size();
        int target = total >> 1;
        vector <bool> dp(target + 1, false);
        dp[0] = true;

        if(nums[0] <= target)
            dp[nums[0]] = true;

        for(int i = 1; i < n; i++)
        {
            for(int k = target; k >= 1; k--)
            {
                if(nums[i] <= k)
                    dp[k] = dp[k] || dp[k - nums[i]];
            }
        }

        return dp[target];
    }
};