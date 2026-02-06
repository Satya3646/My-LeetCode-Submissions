class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();

        // Since we need to keep track of min and max of a window just sort the array.
        // Since order of elements need not be preserved we can sort.
        sort(nums.begin(), nums.end()); 

        int i = 0, j = 0;
        int maxLen = 0;
        // Needed window state : max <= k * min
        while(j < n)
        {
            while(i < j && 1LL*nums[j] > 1LL*k*nums[i]) // Shrink while condition not satisfied.
                i++;
            if(nums[i] >= nums[j] / k)
                maxLen = max(maxLen, j-i+1);
            j++;
        }
        // Now we have the maximum length of the window that satisfies our condition.
        // Excluding this window we need to remove all other elements.
        return n-maxLen;
    }
};