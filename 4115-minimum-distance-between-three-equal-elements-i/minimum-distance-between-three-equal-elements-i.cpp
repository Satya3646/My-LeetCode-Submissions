class Solution {
public:
    int minimumDistance(vector <int> &nums)
    {
        int n = nums.size();

        // Get the sorted order indices of nums.
        vector <int> indx(n);
        iota(indx.begin(), indx.end(), 0);
        sort(indx.begin(), indx.end(), [&nums](int a, int b)
        {
            if(nums[a] == nums[b]) // for same values indices will be in sorted order.
                return a < b;
            return nums[a] < nums[b];
        });

        int minDist = INT_MAX;
        // Consecutive occourences will result in smallest distances.
        for(int x = 2; x < n; x++)
        {
            int i = indx[x-2];
            int j = indx[x-1];
            int k = indx[x];
            if(nums[i] == nums[j] && nums[j] == nums[k])
                minDist = min(minDist, abs(i-j) + abs(j-k) + abs(k-i));
        }

        return minDist == INT_MAX? -1: minDist;
    }
};