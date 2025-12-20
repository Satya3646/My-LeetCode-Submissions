class Solution {
public:
    void dfs(int node, int n, const vector <vector <int>> &adj, vector <bool> &visited)
    {
        if(node == n)
            return;
        visited[node] = 1;
        for(int i = 0; i < n; i++)
        {
            if(adj[node][i] && !visited[i])
                dfs(i, n, adj, visited);
        }
    }

    int findCircleNum(vector <vector <int>> &adj) {
        int n = adj.size();
        vector <bool> visited(n, false);
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                cnt++;
                dfs(i, n, adj, visited);
            }
        }
        return cnt;
    }
};