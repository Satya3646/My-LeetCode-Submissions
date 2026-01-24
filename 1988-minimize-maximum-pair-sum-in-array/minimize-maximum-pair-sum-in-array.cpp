class Solution {
public:
    int minPairSum(vector <int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = n-1;
        int maxPair = INT_MIN;
        while(i < j)
        {
            maxPair = max(maxPair, nums[i] + nums[j]);
            i++;
            j--;
        }
        return maxPair;
    }
};