class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <vector <int>> reverseGraph(n);
        vector <int> indegree(n);
        for(int i = 0; i < n; i++)
        {
            indegree[i] = graph[i].size();
            for(int node : graph[i])
            {
                reverseGraph[node].push_back(i);
            }
        }

        vector <int> safeNodes;
        safeNodes.reserve(n);
        queue <int> q;
        for(int i = 0; i < n; i++)
            if(!indegree[i])
                q.push(i);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(int i : reverseGraph[node])
            {
                if(!--indegree[i])
                    q.push(i);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};