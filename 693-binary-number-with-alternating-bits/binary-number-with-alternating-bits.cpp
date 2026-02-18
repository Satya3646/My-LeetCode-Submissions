class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev;
        while(n)
        {
            prev = n&1;
            n >>= 1;
            if(prev == (n&1))
                return false;
        }
        return true;
    }
};