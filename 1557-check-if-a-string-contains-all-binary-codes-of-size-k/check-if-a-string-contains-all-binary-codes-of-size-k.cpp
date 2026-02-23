class Solution {
public:
    bool hasAllCodes(string &s, int k)
    {
        int n = s.size();

        // Edge cases.
        // 1. n < k ==> number of substrings is never k.
        // 2. (n-k+1) < (1 << k) ==> no. of substrings of size k is less than
        //                           the binary codes possible of size k.
        if(n < k || (n - k + 1) < (1 << k))
            return false;
        
        // Hash set to store unique codes.
        unordered_set <string> codes;

        for(int i = 0; i <= n-k; i++)
            codes.insert(s.substr(i, k));

        // if the no. of unique codes is not 2^k then return false.
        return codes.size() == (1 << k);
    }
};