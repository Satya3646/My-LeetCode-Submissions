const int mod = 1e9+7;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        
        for(vector <int> &q : queries)
        {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            for(int i = l; i <= r; i += k)
                nums[i] = (1LL * nums[i] * v ) % mod;
        }

        int ans = 0;
        for(int i : nums)
            ans ^= i;
        
        return ans;
    }
};