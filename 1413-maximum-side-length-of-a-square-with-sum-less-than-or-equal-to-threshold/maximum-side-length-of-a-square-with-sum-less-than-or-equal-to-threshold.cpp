class Solution {
public:
    bool check(int k, int i, int j, int threshold, vector <vector <int>> &prefix)
    {
        if(i + k > prefix.size()-1 || j + k > prefix[0].size()-1)
            return false;
        int sum = prefix[i+k][j+k] 
                - prefix[i+k][j-1] 
                - prefix[i-1][j+k] 
                + prefix[i-1][j-1];
        return sum <= threshold;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        vector <vector <int>> prefix(m+1, vector <int> (n+1, 0));
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                prefix[i][j] = mat[i-1][j-1] 
                             + prefix[i-1][j] 
                             + prefix[i][j-1] 
                             - prefix[i-1][j-1];

        int maxSide = 0;
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                int low = 0, high = min(m, n);
                while(low <= high)
                {
                    int mid = low + ((high - low) >> 1);
                    if(check(mid, i, j, threshold, prefix))
                    {
                        maxSide = max(maxSide, mid+1);
                        low = mid+1;
                    }
                    else
                        high = mid-1;
                }
            }
        }

        return maxSide;
    }
};