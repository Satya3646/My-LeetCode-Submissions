class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Vertical cuts.
        vector <long long> prefix(n, 0);
        long long preSum = 0, suffixSum = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                prefix[i] += grid[j][i];
            suffixSum += prefix[i];
        }

        for(int i = 0; i < n; i++)
        {
            preSum += prefix[i];
            suffixSum -= prefix[i];

            if(preSum == suffixSum)
                return true;
        }

        // Horizontal cuts.
        prefix.assign(m, 0);
        preSum = 0; suffixSum = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
                prefix[i] += grid[i][j];
            suffixSum += prefix[i];
        }

        for(int i = 0; i < m; i++)
        {
            preSum += prefix[i];
            suffixSum -= prefix[i];

            if(preSum == suffixSum)
                return true;
        }

        return false;
    }
};