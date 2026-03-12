class Solution {
public:
    int robLinear(vector <int> &nums)
    {
        int n = nums.size();
        if(n == 1) // only one house.
            return nums[0];
        vector <int> dp(n, -1);

        dp[0] = nums[0]; // first house robbed.
        dp[1] = max(nums[0], nums[1]); // house with most loot is robbed.

        // From now we either rob the current house or not rob it.
        // When we rob the current house its loot is added to last 2ndly robbed house.
        // If we choose to not rob the house the loot till previous house is carried.
        for(int i = 2; i < n; i++)
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        
        // Return loot left with us at the last house.
        return dp[n-1];
    }

    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if(n == 1) // only one house.
            return nums[0];

        vector <int> tmp1, tmp2;
        for(int i = 0; i < n; i++)
        {
            if(i != 0)
                tmp1.push_back(nums[i]);
            if(i != n-1)
                tmp2.push_back(nums[i]);
        }

        return max(robLinear(tmp1), robLinear(tmp2));
    }
};