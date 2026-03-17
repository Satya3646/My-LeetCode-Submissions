class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        // vector to store the prefix sum of previous row.
        vector <int> prev(n, 0);
        int maxMartix = 0;

        for(int i = 0; i < m; i++)
        {
            vector <int> prefix(n, 0); // prefix vector.
            for(int j = 0; j < n; j++) // update prefix.
                if(matrix[i][j] != 0)
                    prefix[j] = prev[j] + 1;

            // update prev before sorting.
            prev = prefix;

            // Sort the prefix vector since that will be the optimal arragement of columns
            // to get maximal area.
            sort(prefix.rbegin(), prefix.rend());

            // Since all the valuse before current value will be larger than it, a
            // rectagle of height prefix[i] and width i+1 will be formed.
            for(int i = 0; i < n; i++)
                maxMartix = max(maxMartix, prefix[i] * (i+1));
        }

        return maxMartix;
    }
};