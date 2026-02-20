class dsu {
public:
    vector <int> parent;
    vector <int> size;

    dsu(int n)
    {
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
        
        if(ulpu == ulpv)
            return;
        /*
        // here no need any criterion to merging the groups.
        // but using size/rank will make it faster.
        parent[ulpv] = ulpu;
        */

        if(size[ulpv] < size[ulpu])
        {
            parent[ulpv] = ulpu;
            size[ulpu] += size[ulpv];
        }
        else
        {
            parent[ulpu] = ulpv;
            size[ulpv] += size[ulpu];
        }
    }
};

class Solution {
public:
    int removeStones(vector <vector <int>> &stones) 
    {
        int n = stones.size();

        // consider each stone as a node.
        // If the row index or col index of a pair of nodes match then they are connected.
        dsu grid = dsu(n);
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    grid.Union(i, j);

        // find the number of components.
        int cnt = 0;
        for(int i = 0; i < n; i++)
            if(grid.parent[i] == i)
                cnt++;
        
        // from each components one stone is left and rest all can be removed.
        return n - cnt;
    }
};