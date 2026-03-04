const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    bool canSwimToBottom(int water, vector <vector <int>> &grid)
    {
        if(grid[0][0] > water)
            return false;
            
        int n = grid.size();
        vector <vector <bool>> vis(n, vector <bool> (n, false));

        queue <pair <int, int>> q;
        q.push({0, 0});
        vis[0][0] = true;
        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(0 <= nx && nx < n && 0 <= ny && ny < n && 
                   !vis[nx][ny] && 
                   grid[nx][ny] <= water)
                {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        return vis[n-1][n-1];
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int low = 0, high = 2500;
        while(low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if(canSwimToBottom(mid, grid))
                high = mid-1;
            else
                low = mid+1;
        }
        return low;
    }
};