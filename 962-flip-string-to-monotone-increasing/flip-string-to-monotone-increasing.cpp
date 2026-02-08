class Solution {
public:
    int minFlipsMonoIncr(string s)
    {
        int flips = 0, prevOnes = 0;
        for(char c : s)
        {
            if(c == '1') 
                prevOnes++;
            else if(prevOnes)
            {
                flips++;
                prevOnes--;
            }
        }
        return flips;
    }
};