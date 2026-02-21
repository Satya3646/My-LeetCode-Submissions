class Solution {
public:
    int isPrime(int n)
    {
        int sqrtN = sqrt(n);
        int cnt = 0;
        for(int i = 1; i <= sqrtN; i++)
        {
            if(n % i == 0)
            {
                cnt++;
                if(n/i != i)
                    cnt++;
            }
        }
        return cnt == 2;
    }

    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        for(int i = left; i <= right; i++)
            cnt += isPrime(__builtin_popcount(i));
        return cnt;
    }
};