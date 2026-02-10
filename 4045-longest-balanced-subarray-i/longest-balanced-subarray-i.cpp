class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        unordered_set <int> even, odd;
        int maxWindow = 0;
        // n-maxWindow for early terminate since once we find a window of size 'x' 
        // then smaller windows need not be checked.
        for(int i = 0; i < n - maxWindow; i++) 
        {
            even.clear();
            odd.clear();
            for(int j = i; j < n; j++)
            {
                if(nums[j] & 1)
                    odd.insert(nums[j]);
                else
                    even.insert(nums[j]);
                // if size is equal then update the window size to max.
                if(even.size() == odd.size())
                    maxWindow = max(maxWindow, j-i+1);
            }
        }
        return maxWindow;
    }
};