class DSU {
public:
    vector <int> size, parent;
    int components;

    DSU(int n) // constructor.
    {
        components = n; // initially all are disconnected.
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findPar(int node)
    {
        if(parent[node] == node) 
            return node;
        return parent[node] = findPar(parent[node]);
    }

    void Union(int u, int v)
    {
        int ulpu = findPar(u);
        int ulpv = findPar(v);

        if(ulpu == ulpv) // already connected.
            return;

        if(size[ulpu] < size[ulpv]) // V belongs to a larger group so attach U to V.
        {
            parent[ulpu] = ulpv;
            size[ulpv] += size[ulpu];
        }
        else // U belongs to a larger/equal group so attach V to U.
        {
            parent[ulpv] = ulpu;
            size[ulpu] += size[ulpv];
        }

        components--; // since two components became one, decrement.
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) // insufficient connections.
            return -1;
        
        DSU graph = DSU(n); // initialize a disjoint set.
        for(vector <int> &v : connections) // add the connections.
            graph.Union(v[0], v[1]);
        return graph.components - 1; // to connect x components we need x-1 connections.
    }
};