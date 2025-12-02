class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // Sort the intervals based on the endpoints because, we need to keep the intervals with smaller
        // endpoints beacuse these intervals are the one that end early and leave space for the future 
        // larger interval that come
        sort(intervals.begin(),intervals.end(), [](vector <int> &a, vector <int> &b)
        {
            if(a[1] == b[1])
                return a[0] < b[0];
            return a[1] < b[1];
        });
        int ans = 0;
        vector <int> last = intervals[0]; // Keep trakc of the last interval
        for(int i = 1; i < n; i++)
        {
            if(last[1] <= intervals[i][0]) // No overlap so update last since the interval can fit in ans
                last = intervals[i];
            else // An overlapping interval came that too with a larger end time removal of such interval is the favoured case to maximise the total intervals in final state, hence increment ans
                ans++;
        }
        return ans;
    }
};