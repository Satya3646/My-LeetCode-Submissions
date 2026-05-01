class Solution {
public:
    int maxRotateFunction(vector <int> &nums)
    {
        int n = nums.size();

        int f = 0;
        for(int i = 0; i < n; i++)
            f += nums[i] * i;

        int maxF = f;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for(int k = 1; k < n; k++)
        {
            f -= sum;
            f += n * nums[(k-1+n) % n];
            maxF = max(maxF, f);
        }

        return maxF;
    }
};