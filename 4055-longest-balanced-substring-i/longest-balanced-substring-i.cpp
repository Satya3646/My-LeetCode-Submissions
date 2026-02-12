class Solution {
public:
    bool isBalanced(vector <int> &cnt)
    {
        int i = 'a';
        while(i <= 'z' && !cnt[i])
            i++;
        int prev = cnt[i];
        i++;
        while(i <= 'z')
        {
            if(cnt[i] && prev != cnt[i])
                return false;
            i++;
        }
        return true;
    }

    int longestBalanced(string &s)
    {
        int n = s.size();
        vector <int> cnt('z'+1, 0);
        int maxWindow = 0;
        // n-maxWindow for early terminate since once we find a window of size 'x' 
        // then smaller windows need not be checked.
        for(int i = 0; i < n - maxWindow; i++)
        {
            fill(cnt.begin(), cnt.end(), 0);
            for(int j = i; j < n; j++)
            {
                cnt[s[j]]++;
                if(isBalanced(cnt))
                    maxWindow = max(maxWindow, j-i+1);
            }
        }
        return maxWindow;
    }
};