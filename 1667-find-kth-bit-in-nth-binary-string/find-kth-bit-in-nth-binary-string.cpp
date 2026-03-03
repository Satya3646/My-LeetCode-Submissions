class Solution {
public:
    char findKthBit(int n, int k)
    {
        if(n == 1) // Base case : S0 = "0".
            return '0';
        
        int len = (1 << n) - 1; // calculate the length of Sn.
        int mid = (len >> 1) + 1; // middle index for Sn.
    
        if(k < mid) // if k is less than mid then search the left half.
            return findKthBit(n-1, k);
        else if(k == mid) // if k is the middle then return '1' since mid is always 1.
            return '1';
        
        // if k is in the right half the get the bit at index len-k+1 and invert it.
        char c = findKthBit(n-1, len - k + 1);
        return c == '0'? '1': '0';
    }
};