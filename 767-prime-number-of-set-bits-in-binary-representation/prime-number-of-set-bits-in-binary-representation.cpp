const unordered_set <int> primes = {2, 3, 5, 7, 11, 13, 17, 19};

class Solution {
public:
    int isPrime(int n)
    {
        if(n <= 1)
            return false;
        int sqrtN = sqrt(n);
        int cnt = 0;
        for(int i = 2; i <= sqrtN; i++)
            if(n % i)
                return false;
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        for(int i = left; i <= right; i++)
        {
            // cnt += isPrime(__builtin_popcount(i));
            cnt += (primes.find(__builtin_popcount(i)) != primes.end());
        }
        return cnt;
    }
};