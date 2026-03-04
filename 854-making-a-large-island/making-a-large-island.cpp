class dsu{
    public:
        vector <int> parent, size;
        int maxIsland;
        
        dsu(int n)
        {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
            size.resize(n, 1);
            maxIsland = 0;
        }
        
        int findPar(int node)
        {
            if(node == parent[node])
                return node;
            return parent[node] = findPar(parent[node]);
        }
        
        void Union(int u, int v)
        {
            int ulpu = findPar(u);
            int ulpv = findPar(v);
            
            if(ulpu == ulpv)
                return;
            
            if(size[ulpu] < size[ulpv])
                swap(ulpu, ulpv);
                
            parent[ulpv] = ulpu;
            size[ulpu] += size[ulpv];
            maxIsland = max(maxIsland, size[ulpu]);
        }
};

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        dsu islands = dsu(n*n);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j]) // if current cell is land.
                {    
                    // check and merge with neighboring land.
                    for(int k = 0; k < 4; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        // if neighbor is a land cell and not connected to current 
                        // land cell the connect them.
                        if(0 <= nx && nx < n && 0 <= ny && ny < n && grid[nx][ny] && 
                           islands.findPar(n*nx + ny) != islands.findPar(n*i + j))
                            islands.Union(n*i + j, n*nx + ny);
                    }
                }
            }
        }

        int ans = INT_MIN;
        /* not iterate on the gird, when a 0 is found check how large island will be formed
        by connecting it with neighbors. */
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!grid[i][j]) // 0.
                {
                    set <int> adjacentIslands; // keeps uniqe islands adjacent to current 0.
                    for(int k = 0; k < 4; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(0 <= nx && nx < n && 0 <= ny && ny < n && grid[nx][ny])
                            adjacentIslands.insert(islands.findPar(n*nx + ny));
                    }
                    
                    // current 0 is made 1, so add size of adjacent islands.
                    int mergedSize = 1;
                    for(int i : adjacentIslands)
                        mergedSize += islands.size[i];

                    ans = max(ans, mergedSize);
                }
            }
        }

        // if ans did not update that means there are no 0's in the grid(full grid is island).
        if(ans == INT_MIN)
            return n*n;

        return ans;
    }
};