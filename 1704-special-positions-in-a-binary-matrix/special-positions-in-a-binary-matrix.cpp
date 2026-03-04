class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;

        // calculate the row and column sums to get number of 1's in each of them.
        vector <int> rowSum(m, 0), colSum(n, 0);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
               rowSum[i] += mat[i][j];
               colSum[j] += mat[i][j];
            }
        }

        // if a position in matrix is '1' then check if its rowsum and colsum are both 1.
        // if both are 1 that means current position is a special 1.
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(mat[i][j] && rowSum[i] == 1 && colSum[j] == 1)
                    ans++;

        return ans;
    }
};