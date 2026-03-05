class Solution {
public:
    int minOperations(string &s)
    {
        int n = s.size();

        // starting with a '0' --> even.
        // starting with a '1' --> odd.
        int even = 0, odd = 0;
        for(int i = 0; i < n; i++)
        {
            // if current index is even the s[i] must be '0' else it must be '1'.
            even += (s[i] != ('0' + (i & 1)));

            // if current index is even the s[i] must be '1' else it must be '0'.
            odd += (s[i] != ('0' + !(i & 1)));
        }

        // return the case with minimum operations.
        return min(odd, even);
    }
};