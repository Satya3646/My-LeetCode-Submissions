class Solution {
public:
    int binaryGap(int n) {
        int gap = 0;
        int maxGap = 0;

        while(n && !(n&1)) // shift till the first one appears. 
            n >>= 1;

        while(n)
        {
            if(n & 1) // if bit is 1 then gap has ended.
            {
                maxGap = max(maxGap, gap);
                gap = 1;
            }
            else // if bit is zero the increment gap.
                gap++;
            n >>= 1;
        }
        
        return maxGap;
    }
};