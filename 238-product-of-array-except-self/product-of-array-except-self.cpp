class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector <int> ans(n, 1);
        long long prefixProd = nums[0];
        for(int i = 1; i < n; i++)
        {
            ans[i] = prefixProd;
            prefixProd *= nums[i];
        }
        
        long long suffixProd = nums[n-1];
        for(int i = n-2; i >= 0; i--)
        {
            ans[i] *= suffixProd;
            suffixProd *= nums[i];
        }

        return ans;
    }
};