class Solution {
public:
    int minimumPairRemoval(vector<int>& nums)
    {
        int ops = 0;
        while(!is_sorted(nums.begin(), nums.end()))
        {
            int minSum = INT_MAX;
            int indx = -1;
            for(int i = 1; i < nums.size(); i++)
            {
                if(minSum > nums[i] + nums[i-1])
                {
                    indx = i;
                    minSum = nums[i] + nums[i-1];
                }
            }
            nums[indx-1] = minSum;
            nums.erase(nums.begin() + indx);
            ops++;
        }
        return ops;
    }
};