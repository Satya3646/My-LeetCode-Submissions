class Solution {
public:
    bool canPartitionGrid(vector <vector <int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Maps to keep elements of two partitions for fast search.
        unordered_map <long long, int> part1, part2;
        part1.reserve(m * n);
        part2.reserve(m * n);

        vector <long long> prefix(n, 0);
        long long prefixSum = 0, suffixSum = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                part2[grid[j][i]]++;
                prefix[i] += grid[j][i];
            }
            suffixSum += prefix[i];
        }

        // Vertical cuts.
        for(int i = 0; i < n; i++)
        {
            prefixSum += prefix[i];
            suffixSum -= prefix[i];
            
            // Perfect partition.
            if(prefixSum == suffixSum)
                return true;

            // Update the partition multi-sets.
            for(int j = 0; j < m; j++)
            {
                part1[grid[j][i]]++;
                if(--part2[grid[j][i]] == 0)
                    part2.erase(grid[j][i]);
            }

            if(prefixSum > suffixSum) // deletion from part1.
            {
                long long needed = prefixSum - suffixSum;

                if(i == 0) // part1 is single column.
                {
                    if(grid[0][0] == needed || grid[m-1][0] == needed)
                        return true;
                }
                else if(m == 1) // grid is a single row, then deletion in middle is not allowed.
                {
                    // Only delete boundary elements of part1.
                    if(grid[0][0] == needed || grid[0][i] == needed)
                        return true;
                }
                else // part1 is 2D.
                {
                    if(part1.find(needed) != part1.end())
                        return true;
                }
            }
            else // deletion from part2.
            {
                long long needed = suffixSum - prefixSum;

                if(i == n-2) // part2 is single column.
                {
                    if(grid[0][n-1] == needed || grid[m-1][n-1] == needed)
                        return true;
                }
                else if(m == 1) // grid is a single row, then deletion in middle is not allowed.
                {
                    // Only delete boundary elements of part2.
                    if(grid[0][i+1] == needed || grid[0][n-1] == needed)
                        return true;
                }
                else // part2 is 2D.
                { 
                    if(part2.find(needed) != part2.end())
                        return true;
                }
            }
        }

        swap(prefixSum, suffixSum);
        swap(part1, part2);

        prefix.assign(m, 0);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                prefix[i] += grid[i][j];

        // Horizontal cuts.
        for(int i = 0; i < m; i++)
        {
            prefixSum += prefix[i];
            suffixSum -= prefix[i];

            // Perfect partition.
            if(prefixSum == suffixSum)
                return true;
            
            // Update the partition multi-sets.
            for(int j = 0; j < n; j++)
            {
                part1[grid[i][j]]++;
                if(--part2[grid[i][j]] == 0)
                    part2.erase(grid[i][j]);
            }

            if(prefixSum > suffixSum) // deletion from part1.
            {
                long long needed = prefixSum - suffixSum;

                if(i == 0) // part1 is single column.
                {
                    if(grid[0][0] == needed || grid[0][n-1] == needed)
                        return true;
                }
                else if(n == 1) // grid is a single row, then deletion in middle is not allowed.
                {
                    // Only delete boundary elements of part1.
                    if(grid[0][0] == needed || grid[i][0] == needed)
                        return true;
                }
                else // part1 is 2D
                { 
                    if(part1.find(needed) != part1.end())
                        return true;
                }
            }
            else // deletion from part2.
            {
                long long needed = suffixSum - prefixSum;

                if(i == m-2) // part2 is single column.
                {
                    if(grid[m-1][0] == needed || grid[m-1][n-1] == needed)
                        return true;
                }
                else if(n == 1) // grid is a single row, then deletion in middle is not allowed.
                {
                    // Only delete boundary elements of part2.
                    if(grid[i+1][0] == needed || grid[m-1][0] == needed)
                        return true;
                }
                else // part2 is 2D.
                { 
                    if(part2.find(needed) != part2.end())
                        return true;
                }
            }
        }

        return false;
    }
};
