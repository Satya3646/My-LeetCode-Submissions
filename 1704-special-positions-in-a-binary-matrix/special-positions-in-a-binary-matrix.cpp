class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;

        vector <int> rowSum(m, 0), colSum(n, 0);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
               rowSum[i] += mat[i][j];
               colSum[j] += mat[i][j];
            }
        }

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(mat[i][j] && rowSum[i] == 1 && colSum[j] == 1)
                    ans++;

        return ans;
    }
};