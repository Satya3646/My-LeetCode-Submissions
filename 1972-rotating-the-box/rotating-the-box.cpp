class Solution {
public:
    vector <vector <char>> rotateTheBox(vector <vector <char>> &boxGrid)
    {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        vector <vector <int>> stones(m, vector <int> (1, 0));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(boxGrid[i][j] == '#')
                    stones[i].back()++;
                else if(boxGrid[i][j] == '*')
                    stones[i].push_back(0);
            }
        }
        
        vector <vector <char>> ans(n, vector <char> (m, '.'));
        for(int i = 0; i < m; i++)
        {
            for(int j = n-1; j >= 0; j--)
            {
                if(stones[i].back())
                {
                    ans[j][m-1-i] = '#';
                    stones[i].back()--;
                }
                if(boxGrid[i][j] == '*')
                {
                    ans[j][m-1-i] = '*';
                    stones[i].pop_back();
                }
            }
        }

        return ans;
    }
};