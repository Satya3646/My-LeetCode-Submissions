class Solution {
public:
    int minimumCost(vector<int>& nums)
    {
        int n = nums.size();
        int min1, min2; // The first and second minimum values in nums[1 : n-1].
        min1 = min2 = INT_MAX;
        for(int i = 1; i < n; i++)
        {
            // if current element is < the 1st minimum.
            if(nums[i] < min1)
            {
                min2 = min1;
                min1 = nums[i];
            }
            // else if the value is >= min1 but < than min2.
            else if(nums[i] < min2)
                min2 = nums[i];
        }
        return nums[0] + min1 + min2;
    }
};