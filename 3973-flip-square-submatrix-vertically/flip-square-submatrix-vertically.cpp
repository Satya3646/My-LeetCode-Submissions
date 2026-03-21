class Solution {
public:
    vector <vector <int>> reverseSubmatrix(vector <vector <int>> &grid, int x, int y, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        int top = x, bottom = x + k - 1; // row boundaries of the sub-matrix.
        int left = y, right = y + k - 1; // col boundaries of the sub-matrix.
        while(top < bottom)
        {
            for(int i = left; i <= right; i++) // swap the top and bottom element to reverse.
                swap(grid[top][i], grid[bottom][i]);

            top++;
            bottom--;
        }

        return grid;
    }
};