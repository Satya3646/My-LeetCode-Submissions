class Solution {
public:
    int minFlips(string &s)
    {
        int n = s.size();

        // Pattern 1 = 01010101.....
        // Pattern 2 = 10101010.....
        int misMatchPattern1, misMatchPattern2;
        misMatchPattern1 = misMatchPattern2 = 0;

        // concatenate s with itself to obtain all possible rotation of itself as sliding window.
        s += s;

        for(int i = 0; i < n; i++)
        {
            misMatchPattern1 += (s[i] != ('0' + (i & 1)));
            misMatchPattern2 += (s[i] != ('0' + !(i & 1)));
        }

        int flips = min(misMatchPattern1, misMatchPattern2);
        for(int i = n; i < 2*n; i++)
        {
            if(s[i-n] != ('0' + ((i-n) & 1)))
                misMatchPattern1--;
            if(s[i-n] != ('0' + !((i-n) & 1)))
                misMatchPattern2--;
            if(s[i] != ('0' + (i & 1)))
                misMatchPattern1++;
            if(s[i] != ('0' + !(i & 1)))
                misMatchPattern2++;
            flips = min({flips, misMatchPattern1, misMatchPattern2});
        }

        return flips;
    }
};