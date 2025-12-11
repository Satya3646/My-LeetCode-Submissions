class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map <int, pair <int, int>> horizontal, vertical;
        for(vector <int> v : buildings)
        {
            int x = v[0];
            int y = v[1];
            if(horizontal.find(y) != horizontal.end())
                horizontal[y] = {min(horizontal[y].first, x), max(horizontal[y].second, x)};
            else
                horizontal[y] = {x, x};
            if(vertical.find(x) != vertical.end())
                vertical[x] = {min(vertical[x].first, y), max(vertical[x].second, y)};
            else
                vertical[x] = {y, y};
        }
        int ans = 0;
        for(vector <int> v : buildings)
        {
            int x = v[0];
            int y = v[1];
            if(vertical[x].first < y && y < vertical[x].second &&
               horizontal[y].first < x && x < horizontal[y].second)
                ans++;
        }
        return ans;
    }
};