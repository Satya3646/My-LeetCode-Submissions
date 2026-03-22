class Solution {
public:
    void rotateMatrix(vector <vector <int>> &matrix)
    {
        int n = matrix.size();

        // Transpose.
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);

        // Reverse the rows.
        for(int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());

        return;
    }

    bool findRotation(vector <vector <int>> &mat, vector <vector <int>> &target)
    {
        if(mat == target)
            return true;

        for(int i = 0; i < 3; i++)
        {
            rotateMatrix(mat);
            if(mat == target)
                return true;
        }

        return false;
    }
};