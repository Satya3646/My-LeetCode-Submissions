class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int totalTime = 0;
        for(int i = 1; i < n; i++)
        {
            int dx = abs(points[i][0] - points[i-1][0]);
            int dy = abs(points[i][1] - points[i-1][1]);
            int time = min(dx, dy);
            time += abs(dx - dy);
            totalTime += time;
        }
        return totalTime;
    }
};