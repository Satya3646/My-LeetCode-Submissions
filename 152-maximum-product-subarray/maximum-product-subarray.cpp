class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int n = nums.size();
        int ans = INT_MIN;

        /* Here 0 divides the array into subarrays, so we can get the max product by taking
        prefix product and suffix product we can always take maximum product. */

        /* It is always preferred to consider elements for the subarray product only a single
        -ve elements needs to be exclude which will be handled automatically since we are doing
        both prefix and suffix products at the same time. */

        int prefixProd = 1, suffixProd = 1;
        for(int i = 0; i < n; i++)
        {
            prefixProd *= nums[i];
            suffixProd *= nums[n-i-1];

            ans = max({ans, prefixProd, suffixProd});

            if(prefixProd == 0)
                prefixProd = 1;
            if(suffixProd == 0)
                suffixProd = 1;
        }

        return ans;
    }
};