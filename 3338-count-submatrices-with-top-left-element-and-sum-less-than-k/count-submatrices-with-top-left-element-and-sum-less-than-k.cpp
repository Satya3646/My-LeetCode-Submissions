class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        if(grid[0][0] >= k) 
            return grid[0][0] == k;
        
        int m = grid.size();
        int n = grid[0].size();

        vector <vector <int>> prefixGrid(m, vector <int> (n, 0));
        prefixGrid[0][0] = grid[0][0];
        int ans = 1;

        for(int i = 1; i < n; i++)
        {
            prefixGrid[0][i] = prefixGrid[0][i-1] + grid[0][i];
            if(prefixGrid[0][i] <= k)
                ans++;
        }

        for(int i = 1; i < m; i++)
        {
            prefixGrid[i][0] = prefixGrid[i-1][0] + grid[i][0];
            if(prefixGrid[i][0] <= k)
                ans++;
        }
        
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                prefixGrid[i][j] = prefixGrid[i-1][j] + prefixGrid[i][j-1] - prefixGrid[i-1][j-1] + grid[i][j];
                if(prefixGrid[i][j] <= k)
                    ans++;
                else
                    break;
            }
        }

        return ans;
    }
};