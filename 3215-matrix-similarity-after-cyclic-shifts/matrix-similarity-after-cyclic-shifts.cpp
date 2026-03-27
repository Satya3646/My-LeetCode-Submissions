class Solution {
public:
    bool areSimilar(vector <vector <int>> &mat, int k)
    {
        int m = mat.size();
        int n = mat[0].size();

        k %= n;
        int shift; // indicates direction of shift.
        for(int i = 0; i < m; i++)
        {
            // indicates +1 (right shift) when row is odd & -1 (left shift) when row is even.
            shift = (i & 1)? 1: -1;
            for(int j = 0; j < n; j++)
            {
                // Add +n to index to ensure +ve mod (left shift case).
                if(mat[i][j] != mat[i][(j + k * shift + n) % n])
                    return false;
            }
        }

        return true;
    }
};