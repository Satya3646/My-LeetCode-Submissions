class Solution {
public:
    int minimumDifference(vector<int>& nums, int k)
    {
        int n = nums.size();

        // The dieeference between adjacent elements will be minimized in sorted order.
        sort(nums.begin(), nums.end());

        int i = 0, j = k-1; // place the window.
        int minDiff = INT_MAX;

        // Largest of the window will be at j and the smallest at i.
        while(j < n)
            minDiff = min(minDiff, nums[j++] - nums[i++]);
        return minDiff;
    }
};