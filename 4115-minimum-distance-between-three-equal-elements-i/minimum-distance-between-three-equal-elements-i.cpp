class Solution {
public:
    int minimumDistance(vector <int> &nums)
    {
        int n = nums.size();
        vector <int> indx(n);
        iota(indx.begin(), indx.end(), 0);
        sort(indx.begin(), indx.end(), [&nums](int a, int b)
        {
            if(nums[a] == nums[b])
                return a < b;
            return nums[a] < nums[b];
        });

        int minDist = INT_MAX;
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