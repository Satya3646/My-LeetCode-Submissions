class Solution {
public:
    vector <int> getBiggestThree(vector <vector <int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector <int> ans(3, INT_MIN);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int sum = grid[i][j];

                // Update max
                if(sum > ans[0])
                {
                    ans[2] = ans[1];
                    ans[1] = ans[0];
                    ans[0] = sum;
                }
                else if(sum > ans[1] && sum < ans[0])
                {
                    ans[2] = ans[1];
                    ans[1] = sum;
                }
                else if(sum > ans[2] && sum < ans[1])
                    ans[2] = sum;
            }
        }

        int maxRhombus = ceil(min(m, n) / 2.0);
        for(int k = 1; k <= maxRhombus; k++) // k indicates side length.
        {
            int top = 0, bottom = 2*k;
            while(bottom < m)
            {
                int left = 0, right = 2*k;
                while(right < n)
                {
                    int sum = 0;
                    int row = (top + bottom)/2, col = left;
                    while(row > top && col < (left + right)/2)
                    {
                        sum += grid[row][col];
                        row--;
                        col++;
                    }

                    while(row < (top + bottom)/2 && col < right)
                    {
                        sum += grid[row][col];
                        row++;
                        col++; 
                    }

                    while(row < bottom && col > (left + right)/2)
                    {
                        sum += grid[row][col];
                        row++;
                        col--;
                    }

                    while(row > (top + bottom)/2 && col > left)
                    {
                        sum += grid[row][col];
                        row--;
                        col--;
                    }

                    // Update max
                    if(sum > ans[0])
                    {
                        ans[2] = ans[1];
                        ans[1] = ans[0];
                        ans[0] = sum;
                    }
                    else if(sum > ans[1] && sum < ans[0])
                    {
                        ans[2] = ans[1];
                        ans[1] = sum;
                    }
                    else if(sum > ans[2] && sum < ans[1])
                        ans[2] = sum;

                    left++;
                    right++;
                }

                top++;
                bottom++;
            }
        }

        if(ans[2] == ans[1] || ans[2] == INT_MIN)
            ans.pop_back();
        if(ans[1] == ans[0] || ans[1] == INT_MIN)
            ans.erase(ans.begin()+1);
        return ans;
    }
};