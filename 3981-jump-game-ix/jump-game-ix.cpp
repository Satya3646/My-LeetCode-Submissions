class Solution {
public:
    vector <int> maxValue(vector <int> &nums)
    {
        int n = nums.size();

        vector <int> preMax(n), suffMin(n);
        preMax[0] = nums[0];
        suffMin[n-1] = nums[n-1];
        for(int i = 1; i < n; i++)
            preMax[i] = max(preMax[i-1], nums[i]);
        for(int i = n-2; i >= 0; i--)
            suffMin[i] = min(suffMin[i+1], nums[i]);

        vector <int> ans(n, 0);
        ans[n-1] = preMax[n-1];
        for(int i = n-2; i >= 0; i--)
        {
            if(preMax[i] > suffMin[i+1])
                ans[i] = ans[i+1];
            else
                ans[i] = preMax[i];
        }

        return ans;
    }
};