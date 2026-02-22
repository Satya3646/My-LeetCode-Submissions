class Solution {
public:
    int lengthOfLastWord(string &s)
    {
        int n = s.size();

        // Find the last non-space index by going right to left.
        int j = n-1;
        while(j >= 0 && s[j] == ' ')
            j--;

        // Find the spcae index before the last non-space index by going left.
        int i = j;
        while(i >= 0 && s[i] != ' ')
            i--;
        
        // Now i points to the space before last word and
        // j points to the last letter of the word hence return the difference.
        return j-i;
    }
};