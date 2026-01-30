class Solution {
public:
    int minPairSum(vector <int> &nums)
    {
        int n = nums.size();
        // pair sum is minimized when largest and the smallest elements get paired.
        sort(nums.begin(), nums.end());
        int i = 0, j = n-1; // i points to small value & j points to large value.
        int maxPair = INT_MIN;
        
        while(i < j)
            maxPair = max(maxPair, nums[i++] + nums[j--]);
        return maxPair;
    }
};