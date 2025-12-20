const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    vector <vector <int>> updateMatrix(vector <vector <int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector <vector <int>> nearestZero(m, vector <int> (n, 0));
        vector <vector <bool>> visited(m, vector <bool> (n, false));
        queue <pair <int, int>> q;

        // Push all the zeros into the BFS queue so that only ones reamin unvisited.
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++) 
            { 
                if(mat[i][j] == 0)
                {
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty())
        {
            int qs = q.size();
            for(int i = 0; i < qs; i++)
            {
                auto [x, y] = q.front(); // Unpack the coordinates from the front of the queue.
                q.pop();
                for(int j = 0; j < 4; j++) // iterate the adjacent nodes.
                {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    
                    // if a node is unvisited then it is definitely a one since we added all the zeros beforehand.
                    if(0 <= nx && nx < m && 0 <= ny && ny < n && !visited[nx][ny])
                    {
                        visited[nx][ny] = true;
                        nearestZero[nx][ny] = 1 + nearestZero[x][y]; // current node is +1 distance from its parent.
                        q.push({nx, ny});
                    }
                }
            }
        }
        return nearestZero;
    }
};