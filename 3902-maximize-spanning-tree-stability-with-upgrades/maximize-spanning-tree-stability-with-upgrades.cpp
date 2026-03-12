class dsu{
public:
    vector <int> parent, size;
    int components;
    
    dsu(int n)
    {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
        components = n;
    }
    
    int findPar(int node)
    {
        if(node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }
    
    bool Union(int u, int v)
    {
        int ulpu = findPar(u);
        int ulpv = findPar(v);
        
        if(ulpu == ulpv)
            return false;
        
        if(size[ulpu] < size[ulpv])
            swap(ulpu, ulpv);
            
        parent[ulpv] = ulpu;
        size[ulpu] += size[ulpv];
        components--;
        return true;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k)
    {
        dsu graph = dsu(n);
        vector <vector <int>> freeEdges; // Vector to store the free edges.
        int minStrength = INT_MAX; // keeps minimum strength edge in the graph.
        for(vector <int> &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int strength = edge[2];
            if(edge[3]) // Fixed edge add to graph.
            {
                minStrength = min(minStrength, strength);

                // if union results in cycle then cant have Spanning Tree.
                if(!graph.Union(u, v)) 
                    return -1;
            }
            else // Free edge add to vector.
                freeEdges.push_back(edge);
        }

        // Sort the free edges based on strength (descending).
        sort(freeEdges.begin(), freeEdges.end(), [](vector <int> &a, vector <int> &b)
        {
            return a[2] > b[2];
        });

        int nFreeEdges = freeEdges.size(); // number of unused free edges.
        vector <int> freeEdgesUsed;
        for(int i = 0; i < nFreeEdges; i++)
        {
            int u = freeEdges[i][0];
            int v = freeEdges[i][1];
            int strength = freeEdges[i][2];

            // if free node available doesnt cause a cycle then add it to graph.
            if(graph.Union(u, v))
                freeEdgesUsed.push_back(strength);
        }

        // If graph doesnt form single components then cant form spanning tree.
        if(graph.components != 1)
            return -1;
        
        int nfreeEdgesUsed = freeEdgesUsed.size();

        // The smallest doubled free edge.
        if(k && nfreeEdgesUsed)
            minStrength = min(minStrength, 2*freeEdgesUsed[nfreeEdgesUsed-1]);
        
        // The smallest non-doubled free edge used.
        if(nfreeEdgesUsed-1-k >= 0)
            minStrength = min(minStrength, freeEdgesUsed[nfreeEdgesUsed-1-k]);
        
        return minStrength;
    }
};