class Solution {
public:
    bool areSimilar(vector <vector <int>> &mat, int k)
    {
        int m = mat.size();
        int n = mat[0].size();

        k %= n;
        int shift;
        for(int i = 0; i < m; i++)
        {
            shift = (i & 1)? 1: -1;
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] != mat[i][(j + k * shift + n) % n])
                    return false;
            }
        }

        return true;
    }
};