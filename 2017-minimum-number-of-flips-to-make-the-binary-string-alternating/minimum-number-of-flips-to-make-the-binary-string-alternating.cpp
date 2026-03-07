class Solution {
public:
    int minFlips(string &s)
    {
        int n = s.size();

        // Pattern 1 = 01010101.....
        // Pattern 2 = 10101010.....
        // keeping track of mismatch for pattern 1, we can get mismatch for pattern 2 as n-mismatch.
        int mismatch = 0;
        
        // Place the window from 0 to n-1.
        for(int i = 0; i < n; i++)
            mismatch += (s[i] != ('0' + (i & 1)));

        int flips = min(mismatch, n - mismatch);

        // For strings of even length Type-1 operation has no meaning since 
        // doing Type-1 operation wont reduce the number of filps needed.
        if(n % 2 == 0)
            return flips;

        // For all possible rotations of string get the minimum filps needed.
        for(int i = n; i < 2*n; i++)
        {
            // The same character enters and leaves the window, only the parity of index changes.
            // The character is s[i-n], but leaves at index i-n and enters at index i.
            mismatch -= (s[i-n] != ('0' + ((i-n) & 1)));
            mismatch += (s[i-n] != ('0' + (i & 1)));
            flips = min({flips, mismatch, n - mismatch});
        }

        return flips;
    }
};