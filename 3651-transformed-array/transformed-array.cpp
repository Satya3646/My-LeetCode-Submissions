class Solution {
public:
    vector <int> constructTransformedArray(vector<int>& nums)
    {
        int n = nums.size();
        vector <int> result(n);
        for(int i = 0, num; i < n; i++)
        {
            num = nums[i];
            if(num == 0)
                result[i] = num;
            else if(num > 0) // +ve rotation normal addition.
                result[i] = nums[(i + num) % n];
            else // -ve rotation, result can be -ve so add 'n' and do '%' again.
                result[i] = nums[(((i + num) % n) + n) % n];
        }
        return result;
    }
};