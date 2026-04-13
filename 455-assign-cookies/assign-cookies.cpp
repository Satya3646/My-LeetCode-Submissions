class Solution {
public:
    int findContentChildren(vector<int> &g, vector <int> &s)
    {
        int m = g.size();
        int n = s.size();

        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        
        int j = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(j < m && s[i] >= g[j])
            {
                cnt++;
                j++;
            }
        }

        return cnt;
    }
};