class Solution {
public:
    vector <vector <int>> rotateGrid(vector <vector <int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        int top = 0, bottom = m-1;
        int left = 0, right = n-1;
        while(top <= bottom && left <= right)
        {
            vector <int> layer;
            for(int i = top; i <= bottom; i++)
                layer.push_back(grid[i][left]);
            for(int i = left+1; i <= right; i++)
                layer.push_back(grid[bottom][i]);
            for(int i = bottom-1; i >= top; i--)
                layer.push_back(grid[i][right]);
            for(int i = right-1; i >= left+1; i--)
                layer.push_back(grid[top][i]);

            int tmpK = k;
            tmpK %= layer.size();
            rotate(layer.begin(), layer.begin()+layer.size()-tmpK, layer.end());

            int ptr = 0;
            for(int i = top; i <= bottom; i++)
                grid[i][left] = layer[ptr++];
            for(int i = left+1; i <= right; i++)
                grid[bottom][i] = layer[ptr++];
            for(int i = bottom-1; i >= top; i--)
                grid[i][right] = layer[ptr++];
            for(int i = right-1; i >= left+1; i--)
                grid[top][i] = layer[ptr++];

            top++; bottom--;
            left++; right--;
        }

        return grid;
    }
};