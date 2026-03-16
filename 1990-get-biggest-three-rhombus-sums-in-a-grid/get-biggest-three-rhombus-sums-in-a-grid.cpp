class Solution {
public:
    void updateAns(vector <int> &ans, int sum)
    {
        // Larger than largest value.
        if(sum > ans[0])
        {
            ans[2] = ans[1];
            ans[1] = ans[0];
            ans[0] = sum;
        }
        // Less then largest but greater than 2nd largest.
        else if(sum > ans[1] && sum != ans[0])
        {
            ans[2] = ans[1];
            ans[1] = sum;
        }
        // Less the 2nd largest but greater than 3rd largest.
        else if(sum > ans[2] && sum < ans[1])
            ans[2] = sum;
    }

    vector <int> getBiggestThree(vector <vector <int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector <int> ans(3, INT_MIN); // vector to store top 3 sum.

        // Handle single element rhombus seperately.
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                updateAns(ans, grid[i][j]);
        
        // Max side length depends on m and n.
        int maxRhombus = ceil(min(m, n) / 2.0);
        for(int k = 1; k <= maxRhombus; k++) // k indicates side length.
        {
            // top and bottom corners of the rhombus.
            int top = 0, bottom = 2*k;
            while(bottom < m)
            {
                // left and right corners of the rhombus.
                int left = 0, right = 2*k;
                while(right < n)
                {
                    int sum = 0;
                    int row = (top + bottom)/2, col = left;

                    // Process the top left diagonal.
                    while(row > top && col < (left + right)/2)
                    {
                        sum += grid[row][col];
                        row--;
                        col++;
                    }

                    // Process the top right diagonal.
                    while(row < (top + bottom)/2 && col < right)
                    {
                        sum += grid[row][col];
                        row++;
                        col++; 
                    }
                    
                    // Process the bottom right diagonal.
                    while(row < bottom && col > (left + right)/2)
                    {
                        sum += grid[row][col];
                        row++;
                        col--;
                    }
                    
                    // Process the bottom left diagonal.
                    while(row > (top + bottom)/2 && col > left)
                    {
                        sum += grid[row][col];
                        row--;
                        col--;
                    }

                    // Update max
                    updateAns(ans, sum);

                    left++;
                    right++;
                }

                top++;
                bottom++;
            }
        }

        // Pop duplicates and Unupdated values.
        if(ans[2] == ans[1] || ans[2] == INT_MIN)
            ans.pop_back();
        if(ans[1] == ans[0] || ans[1] == INT_MIN)
            ans.erase(ans.begin()+1);

        return ans;
    }
};