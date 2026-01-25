class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0, j = k-1;
        int minDiff = INT_MAX;
        
        while(j < n)
        {
            minDiff = min(minDiff, nums[j] - nums[i]);
            i++;
            j++;
        }
        return minDiff;
    }
};