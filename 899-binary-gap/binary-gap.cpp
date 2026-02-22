class Solution {
public:
    int binaryGap(int n) {
        int gap = 0;
        int maxGap = 0;
        while(n && !(n&1))
            n >>= 1;
        while(n)
        {
            if(n & 1)
            {
                maxGap = max(maxGap, gap);
                gap = 1;
            }
            else
                gap++;
            n >>= 1;
        }
        // return maxGap? maxGap+1: 0;;
        return maxGap;
    }
};