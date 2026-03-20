class Solution {
public:
    vector <vector <int>> minAbsDiff(vector <vector <int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector <vector <int>> ans(m-k+1, vector <int> (n-k+1, 0));
        if(k == 1) // single element diff is 0.
            return ans;

        // Set to store distinct elements in sorted order since difference
        // will be minimum when the elements are in sorted order.
        set <int> s;
        int top = 0, bottom = k-1;
        while(bottom < m)
        {
            int left = 0, right = k-1;
            while(right < n)
            {
                // Insert the KxK window element into set.
                for(int i = top; i <= bottom; i++)
                    for(int j = left; j <= right; j++)  
                        s.insert(grid[i][j]);

                // Iterate over the set to find the minimum difference.
                int prev = *s.begin();
                int minDiff = INT_MAX;
                auto it = s.begin();
                it++;
                while(it != s.end())
                {
                    minDiff = min(minDiff, abs(prev - *it));
                    prev = *it;
                    it++;
                }

                ans[top][left] = minDiff == INT_MAX? 0: minDiff;

                // Remove all elements from the set before sliding the window.
                s.clear();

                left++;
                right++;
            }

            top++;
            bottom++;
        }

        return ans;
    }
};