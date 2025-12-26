class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector <vector <pair <int, int>>> adj(n+1);
        for(vector <int> &v : times)
            adj[v[0]].push_back({v[1], v[2]});
        
        vector <int> minTime(n+1, INT_MAX);
        minTime[0] = -1;
        priority_queue <pair <int, int>,
                        vector <pair <int, int>>,
                        greater <pair <int, int>>> pq;
        pq.push({0, k});
        minTime[k] = 0;

        while(!pq.empty())
        {
            auto [time, node] = pq.top();
            pq.pop();

            if(minTime[node] < time)
                continue;

            for(auto &[i, ti] : adj[node])
            {
                if(minTime[i] > time + ti)
                {
                    minTime[i] = time + ti;
                    pq.push({minTime[i], i});
                }
            }
        }

        int ans =  *max_element(minTime.begin(), minTime.end());
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};