class Solution {
public:
    vector <vector <int>> reverseSubmatrix(vector <vector <int>> &grid, int x, int y, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        int top = x, bottom = x + k - 1;
        int left = y, right = y + k - 1;
        while(top < bottom)
        {
            for(int i = left; i <= right; i++)
                swap(grid[top][i], grid[bottom][i]);

            top++;
            bottom--;
        }

        return grid;
    }
};