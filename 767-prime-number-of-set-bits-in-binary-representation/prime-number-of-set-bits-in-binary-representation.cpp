const unordered_set <int> primes = {2, 3, 5, 7, 11, 13, 17, 19};

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        for(int i = left; i <= right; i++)
            cnt += (primes.find(__builtin_popcount(i)) != primes.end());
        return cnt;
    }
};