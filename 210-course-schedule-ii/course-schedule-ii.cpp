class Solution {
public:
    bool dfs(int node, vector <vector <int>> &adj, vector <bool> &visited, vector <bool> &pathVis, vector <int> &order)
    {
        // marks as visited.
        visited[node] = true;
        pathVis[node] = true;

        for(int i : adj[node]) // adjacents.
        {
            if(!visited[i]) // not visited
            {
		        if(dfs(i, adj, visited, pathVis, order)) // if a cycle is found in the deeper parts then return true.
				    return true;
            }
            else if(pathVis[i]) // current node is already visited and alsO part of the current path --> cycle.
                return true;
        }
        order.push_back(node);
        pathVis[node] = false; // restore pathVis before backtracking.
        return false;
    }

    bool isCyclic(int n, vector <vector <int>> &adj, vector <int> &order)
    {
        vector <bool> visited(n, false); // global visited array to capture components.
        vector <bool> pathVis(n, false); // visited array to keep track of nodes visited only on the current path.

        for(int i = 0; i < n; i++)
            if(!visited[i] && dfs(i, adj, visited, pathVis, order))
                return true;
        return false;
    }

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector <vector <int>> adj(n);
        for(vector <int> &v : prerequisites) // if we need 'a' the first we need to do 'b' --> edge goes form b to a.
            adj[v[1]].push_back(v[0]);
        vector <int> order;
        if(isCyclic(n, adj, order)) // if the graph is cyclic the we are stuck in an infinite loop, so just return empty order.
            return vector <int> {};

        // reverse the order before returning 
        reverse(order.begin(), order.end()); 
        return order;
    }
};