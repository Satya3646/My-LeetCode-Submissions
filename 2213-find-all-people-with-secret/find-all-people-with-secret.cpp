class Solution {
public:
    class Disjoint {
    public:
        vector<int> par;
        vector<int> siz;

        Disjoint(int n) {
            par.resize(n);
            siz.resize(n, 1);

            for (int i = 0; i < n; i++) {
                par[i] = i;
            }
        }

        int find(int x) {
            if (x == par[x]) {
                return x;
            }

            return par[x] = find(par[x]);
        }

        void Union(int x, int y) {
            int par_x = find(x);
            int par_y = find(y);

            if (par_x == par_y) {
                return;
            }

            if (siz[par_x] >= siz[par_y]) {
                siz[par_x] += siz[par_y];
                par[par_y] = par_x;
            } else {
                siz[par_y] += siz[par_x];
                par[par_x] = par_y;
            }
        }

        void reset(int node){
            siz[node]=1;
            par[node]=node;

        }
    };

    static bool check(vector<int> a, vector<int> b) { return a[2] < b[2]; }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
       // sort(meetings.begin(), meetings.end(), check);

        vector<int> ans;

        map<int,vector<pair<int,int>>> mp;

        for(auto i: meetings){
            mp[i[2]].push_back({i[0],i[1]});
        }

        Disjoint ds(n);

        
        ds.Union(0,firstPerson);

        for(auto i: mp){
            
            for(auto j: i.second){
                ds.Union(j.first,j.second);
            }

            for(auto j: i.second){
                int x = j.first;
                int y = j.second;

                if(ds.find(x)!=ds.find(0) && ds.find(y)!=ds.find(0)){
                    ds.reset(x);
                    ds.reset(y);
                }
            }

        
        }

        for(int i=0;i<n;i++){
            if(ds.find(i)==ds.find(0)){
                ans.push_back(i);
            }
        }

        return ans;




      
    }
};