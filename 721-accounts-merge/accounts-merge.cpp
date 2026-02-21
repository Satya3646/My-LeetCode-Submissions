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

        // map each email to index of the username in accounts vector.
        for(int i = 0; i < n; i++)
        {
            vector <string> &v = accounts[i]; // create a reference.
            int m = v.size();
            for(int j = 1; j < m; j++) // iterate the emails.
            {
                auto it = emailToAccount.find(v[j]);
                if(it == emailToAccount.end()) // if not already indexed.
                    emailToAccount[v[j]] = i;
                else // already indexed, the the email is appearing a 2nd time hence do union.
                    merge.Union(it->second, i);
            }
        }

        // Combine the merged accounts emails into a single vector.
        vector <vector <string>> mergedMails(n);
        for(auto &[email, node] : emailToAccount)
        {
            // use the ultimate parent as index.
            node = merge.findPar(node);
            mergedMails[node].push_back(email);
        }

        vector <vector <string>> ans;
        for(int i = 0; i < n; i++)
        {
            vector <string> &emails = mergedMails[i]; // create reference.

            if(emails.empty()) // if no emails the skip.
                continue;
            
            sort(emails.begin(), emails.end()); // sort the emails to get lexi-order.

            ans.push_back({accounts[i][0]}); // add the username to ans as last element.
            // append the group of merged emails to the end element of ans.
            ans.back().insert(ans.back().end(), emails.begin(), emails.end());
        }

        return ans;
    }
};