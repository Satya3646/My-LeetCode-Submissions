class Solution {
public:
    int countBinarySubstrings(string &s)
    {
        int n = s.size();
        int ans = 0;
        int  curr = 1, prev = 0;
        for(int i = 1; i < n; i++)
        {
            if(s[i] == s[i-1]) // increment till block breaks.
                curr++;
            else // block broke so update.
            {
                // now the current block and prev block share, 1s and 0s, 
                // the length will the minimum one.
                ans += min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }
        // account for the last block.
        ans += min(prev, curr);
        return ans;
    }
};