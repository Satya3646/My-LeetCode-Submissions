class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int maxK = 1;
        int k = 2;
        while(k <= min(m, n)) // size of magic square.
        {
            bool foundSquare = false; // indicates if a magic square for current k is found or not.
            int top = 0, bottom = k-1; // top and bottom edges.
            while(bottom < m)
            {
                int left = 0, right = k-1; // left and right edges.
                while(right < n)
                {
                    bool flag = true; // true if current window is a magic square.
                    int sum = 0; // sum value to check with all other dimensions.
                    for(int i = left; i <= right; i++)
                        sum += grid[top][i];

                    // check row sum.
                    for(int i = top+1; i <= bottom; i++)
                    {
                        int rowSum = 0;
                        for(int j = left; j <= right; j++) 
                            rowSum += grid[i][j];
                        if(rowSum != sum)
                            flag = false;
                    }

                    // check column sum.
                    for(int i = left; i <= right && flag; i++)
                    {
                        int colSum = 0;
                        for(int j = top; j <= bottom; j++) 
                            colSum += grid[j][i]; 
                        if(colSum != sum)
                            flag = false;
                    }

                    // check diagonals.
                    int d1 = 0, d2 = 0;
                    for(int i = 0; i < k && flag; i++)
                    {    
                        d1 += grid[top + i][left + i];
                        d2 += grid[top + i][right - i];
                    }
                    if(d1 != sum || d2 != sum)
                        flag = false;

                    if(flag) // current window is a magic square.
                    {
                        // no need to check further go for next k square.
                        foundSquare = true;
                        break;
                    }

                    // move the window to right.
                    right++;
                    left++;
                }

                // move the window down.
                top++;
                bottom++;
            }
            
            if(foundSquare) // if a sqaure has been found then update the maxK value.
                maxK = k;
            k++;
        }
        return maxK;
    }
};