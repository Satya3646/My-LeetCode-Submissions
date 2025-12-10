class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        // Computer 0 can act as key for all the computers.
        int key = complexity[0];
        for(int i = 1; i < n; i++) // If a computer with same or less complexity exists then zero 
            if(complexity[i] <= key) // cant unlock hence no order exists.
                return 0;
        // if zero can unlock all the computers then ans is arrangement of n-1 computers in different ways.
        int mod = 1e9+7;
        int k = n-1;
        long long ans = 1;
        while(k != 1)
            ans *= k--,
            ans %= mod;
        return ans;
    }
};