class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int maxK = 1;
        int k = 2;
        while(k <= min(m, n))
        {
            bool foundSquare = false;
            int top = 0, bottom = k-1;
            while(bottom < m)
            {
                int left = 0, right = k-1;
                while(right < n)
                {
                    bool flag = true;
                    int sum = 0; // sum value to check with all other dimensions.
                    for(int i = left; i <= right; i++)
                        sum += grid[top][i];

                    // check row sum.
                    for(int i = top+1; i <= bottom; i++)
                    {
                        int rowSum = 0;
                        for(int j = left; j <= right; j++)
                        {
                            rowSum += grid[i][j];
                        }
                        if(rowSum != sum)
                            flag = false;
                    }

                    // check column sum.
                    for(int i = left; i <= right && flag; i++)
                    {
                        int colSum = 0;
                        for(int j = top; j <= bottom; j++)
                        {
                            colSum += grid[j][i];
                        }
                        if(colSum != sum)
                            flag = false;
                    }

                    // check diagonals.
                    int diagSum = 0;
                    for(int i = 0; i < k && flag; i++)
                        diagSum += grid[top + i][left + i];
                    if(diagSum != sum)
                        flag = false;
                    
                    diagSum = 0;
                    for(int i = 0; i < k && flag; i++)
                        diagSum += grid[top + i][right - i];
                    if(diagSum != sum)
                        flag = false;

                    if(flag) // current window is a magic square.
                    {
                        // no need to check further go for next kxk square.
                        foundSquare = true;
                        break;
                    }
                    right++;
                    left++;
                }
                top++;
                bottom++;
            }
            
            if(foundSquare)
                maxK = k;
            k++;
        }
        return maxK;
    }
};