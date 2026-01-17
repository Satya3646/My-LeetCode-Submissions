class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long maxSide = 0;
        
        // Iterate over all distinct pairs of rectangles.
        for(int i = 0; i < n; i++) // select Rectangle 1.
        {
            for(int j = i+1; j < n; j++) // select Rectangle 2.
            {
                // Rectangle 1.
                int a1 = bottomLeft[i][0];
                int b1 = bottomLeft[i][1];
                int c1 = topRight[i][0];
                int d1 = topRight[i][1];

                // Rectangle 2.
                int a2 = bottomLeft[j][0];
                int b2 = bottomLeft[j][1];
                int c2 = topRight[j][0];
                int d2 = topRight[j][1];
                
                // Check if they intersect.
                if(!(c1 <= a2 || c2 <= a1 || d1 <= b2 || d2 <= b1))
                {
                    // we take the min intersection region side to form a square.
                    maxSide = max(maxSide, 1LL * min(min(c1, c2) - max(a1, a2), 
                                                     min(d1, d2) - max(b1, b2)));
                }
            }
        }

        // return the area.
        return maxSide * maxSide;
    }
};