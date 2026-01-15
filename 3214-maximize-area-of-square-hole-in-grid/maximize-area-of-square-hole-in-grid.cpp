class Solution {
public:
    int longestLenSequence(unordered_set <int> &s)
    {
        int maxLen = 0;
        for(auto i : s)
        {
            // prev val of sequence not in set, then it can be start of sequence.
            if(s.find(i-1) == s.end())
            {
                int cnt = 0;
                while(s.find(i++) != s.end()) // count the sequence.
                    cnt++;
                maxLen = max(maxLen, cnt); // update.
            }
        }
        return maxLen;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars)
    {
        // put both vectors into sets for fast search.
        unordered_set <int> h(hBars.begin(), hBars.end());
        unordered_set <int> v(vBars.begin(), vBars.end());

        // we need to find the max consecutive sequence in the hBars and vBars both.
        // then the minimum lenght will form a square.
        // Removing one bar give two length hence the +1.
        int maxHlen = longestLenSequence(h) + 1;
        int maxVlen = longestLenSequence(v) + 1;

        return pow(min(maxHlen, maxVlen), 2);
    }
};