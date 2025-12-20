const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) // if current pixel is same color then return.
            return image;

        int m = image.size();
        int n = image[0].size();
        int original = image[sr][sc]; // Preserve the original color of given pixel.

        queue <pair <int, int>> q;
        // Color the starting pixel and push to queue to start traversal.
        image[sr][sc] = color;
        q.push({sr, sc});

        while(!q.empty())
        {
            int qs = q.size();
            for(int i = 0; i < qs; i++)
            {
                auto [x, y] = q.front(); // Unpack the coordinates.
                q.pop();
                for(int j = 0; j < 4; j++) // Check the adjacent pixels.
                {
                    int newX = x + dx[j];
                    int newY = y + dy[j];
                    // if an adjacent pixel is the same color as the starting pixel then we need to color it.
                    if(0 <= newX && newX < m && 0 <= newY && newY < n && image[newX][newY] == original)
                    {
                        image[newX][newY] = color;
                        q.push({newX, newY});
                    }
                }
            }
        }
        return image;
    }
};