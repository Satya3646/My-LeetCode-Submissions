class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Prefix vector that maintains X & Y counts.
        vector <vector <pair <int, int>>> prefixGrid(m, vector <pair <int, int>> (n));
        prefixGrid[0][0] = {(grid[0][0] == 'X'), (grid[0][0] == 'Y')};
        int ans = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                prefixGrid[i][j] = make_pair(grid[i][j] == 'X', grid[i][j] == 'Y');

                if(i > 0)
                {
                    prefixGrid[i][j].first += prefixGrid[i-1][j].first;
                    prefixGrid[i][j].second += prefixGrid[i-1][j].second;
                }
                if(j > 0)
                {
                    prefixGrid[i][j].first += prefixGrid[i][j-1].first;
                    prefixGrid[i][j].second += prefixGrid[i][j-1].second;
                }
                if(i > 0 && j > 0)
                {
                    prefixGrid[i][j].first -= prefixGrid[i-1][j-1].first;
                    prefixGrid[i][j].second -= prefixGrid[i-1][j-1].second;
                }

                // Increment ans if atleast one X is present and X & Y counts are equal.
                if(prefixGrid[i][j].first > 0 && prefixGrid[i][j].first == prefixGrid[i][j].second)
                    ans++;
            }
        }

        return ans;
    }
};