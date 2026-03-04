const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    bool canSwimToBottom(int water, vector <vector <int>> &grid)
    {
        // starting position is not submerged yet so cant start swimming.
        if(grid[0][0] > water) 
            return false;
            
        int n = grid.size();
        vector <vector <bool>> vis(n, vector <bool> (n, false));

        queue <pair <int, int>> q; // BFS queue.
        q.push({0, 0});
        vis[0][0] = true;
        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) // adjacent neighbors.
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(0 <= nx && nx < n && 0 <= ny && ny < n && // valid neighbor index
                   !vis[nx][ny] && // not visited
                   grid[nx][ny] <= water) // submerged.
                {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        // if bottom last cell was reachable then return true.
        return vis[n-1][n-1];
    }
    
    int swimInWater(vector<vector<int>>& grid)
    {
        /* We can do B.S. on the answer space, since monotonicity holds, if we cant 
        swim to bottom on current time, the all smaller time values will also not allow
        use to swim to the bottom hence we can omit them from answer space. */ 
        int low = 0, high = 2500;
        while(low <= high)
        {
            int mid = low + ((high - low) >> 1);
            // if we can reach bottom at current mid, the go left to minimize it.
            if(canSwimToBottom(mid, grid))
                high = mid-1;
            // if current mid doesnt allow us to swim to bottom go right to increase it.
            else
                low = mid+1;
        }
        return low;
    }
};