class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int key = complexity[0];
        for(int i = 1; i < n; i++)
            if(complexity[i] <= key)
                return 0;
        int mod = 1e9+7;
        int k = n-1;
        long long ans = 1;
        while(k != 1)
            ans *= k--,
            ans %= mod;
        return ans;
    }
};