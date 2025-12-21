class Solution {
public:
    int minDeletionSize(vector<string>& strs)
    {
        int n = strs.size();
        int m = strs[0].size();
        vector <bool> sorted(n, false);
        int toDelete = 0;
        for(int i = 0; i < m; i++)
        {
            bool bad = false;
            for(int j = 1; j < n; j++)
            {
                if(!sorted[j] && strs[j][i] < strs[j-1][i])
                {
                    bad = true;
                    break;
                }
            }
            if(bad)
            {
                toDelete++;
                continue;
            }
            for(int j = 1; j < n; j++)
            {
                if(!sorted[j] && strs[j][i] > strs[j-1][i])
                    sorted[j] = true;
            }
        }
        return toDelete;
    }
};