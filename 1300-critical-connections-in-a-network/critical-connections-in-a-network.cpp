class Solution {
public:
    void dfs(int node, int parent, vector <vector <int>> &adj, vector <int> &vis, vector <int> &low, vector <int> &tin, int time, vector <vector <int>> &bridges)
    {
        vis[node] = 1;
        low[node] = tin[node] = time;

        for(int i : adj[node])
        {
            if(!vis[i])
            {
                dfs(i, node, adj, vis, low, tin, time+1, bridges);
                low[node] = min(low[node], low[i]);

                if(low[i] > tin[node])
                    bridges.push_back({node, i});
            }
            else if(i != parent)
                low[node] = min(low[node], low[i]);
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections)
    {
        vector <vector <int>> adj(n);
        for(vector <int> &v : connections)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        vector <int> vis(n, 0), low(n), tin(n);
        vector <vector <int>> bridges;
        dfs(0, -1, adj, vis, low, tin, 1, bridges);
        return bridges;
    }
};