class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        // pop all 32 bits from n from right and push them to right of res.
        for(int i = 0; i < 32; i++) 
        {
            res <<= 1;
            if(n & 1) // current bit if res will be set only if n has a set bit.
                res |= 1;
            n >>= 1;
        }
        return res;
    }
};