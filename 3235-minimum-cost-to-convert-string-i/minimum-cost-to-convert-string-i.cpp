class Solution {
public:
    long long minimumCost(string &source, 
                          string &target, 
                          vector<char>& original, 
                          vector<char>& changed, 
                          vector<int>& cost)
    {
        int n = source.size();
        vector <vector <int>> dist('z'+1, vector <int> ('z'+1, INT_MAX));
        for(char c = 'a'; c <= 'z'; c++)
            dist[c][c] = 0;
        int E = original.size();
        for(int i = 0; i < E; i++)
            dist[original[i]][changed[i]] = min(dist[original[i]][changed[i]], cost[i]);
        for(char k = 'a'; k <= 'z'; k++)
        {
            for(char i = 'a'; i <= 'z'; i++)
            {
                for(int j = 'a'; j <= 'z'; j++)
                {
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        long long minCost = 0;
        for(int i = 0; i < n; i++)
        {
            if(dist[source[i]][target[i]] == INT_MAX)
                return -1;
            minCost += dist[source[i]][target[i]];
        }
        return minCost;
    }
};