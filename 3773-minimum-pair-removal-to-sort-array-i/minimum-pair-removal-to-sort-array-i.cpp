class Solution {
public:
    int minimumPairRemoval(vector<int>& nums)
    {
        int ops = 0; // to count operations.
        while(!is_sorted(nums.begin(), nums.end())) // iterate till nums is not sorted.
        {
            int minSum = INT_MAX;
            int indx = -1; // sotres first occourence of minimum sum.
            for(int i = 1; i < nums.size(); i++)
            {
                if(minSum > nums[i] + nums[i-1])
                {
                    indx = i;
                    minSum = nums[i] + nums[i-1];
                }
            }
            // overwrite the value at indx with minSum and delete the element at indx.
            nums[indx-1] = minSum;
            nums.erase(nums.begin() + indx);
            ops++;
        }
        return ops;
    }
};