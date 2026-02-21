class dsu {
public:
    vector <int> parent, size;

    dsu(int n)
    {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
    }

    int findPar(int node)
    {
        if(node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }

    void Union(int u, int v)
    {
        int ulpu = findPar(u);
        int ulpv = findPar(v);

        if(ulpu == ulpv)
            return;
        
        if(size[ulpu] < size[ulpv])
            swap(ulpu, ulpv);

        parent[ulpv] = ulpu;
        size[ulpu] += size[ulpv];
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map <string, int> emailToAccount;
        dsu merge = dsu(n);

        for(int i = 0; i < n; i++)
        {
            vector <string> &v = accounts[i];
            int m = v.size();
            for(int j = 1; j < m; j++)
            {
                auto it = emailToAccount.find(v[j]);
                if(it == emailToAccount.end())
                    emailToAccount[v[j]] = i;
                else
                    merge.Union(it->second, i);    
            }
        }

        vector <vector <string>> mergedMails(n);
        for(auto &[email, node] : emailToAccount)
        {
            node = merge.findPar(node);
            mergedMails[node].push_back(email);
        }

        vector <vector <string>> ans;
        for(int i = 0; i < n; i++)
        {
            vector <string> &emails = mergedMails[i];

            if(emails.empty())
                continue;
            
            sort(emails.begin(), emails.end());

            ans.push_back({accounts[i][0]});
            ans.back().insert(ans.back().end(), emails.begin(), emails.end());
        }

        return ans;
    }
};