



class Solution {
public:
    bool done = false;
    vector <int> count;
    vector <int> sum;

    void preCompute()
    {
        done = true;
        const int MAX = 1e5;
        count.resize(MAX+1, 1);
        sum.resize(MAX+1, 1);

        for(int i = 2; i <= MAX; i++)
        {
            for(int j = i; j <= MAX; j += i)
            {
                count[j]++;
                sum[j] += i;
            }
        }
    }

    int sumFourDivisors(vector<int>& nums) {
        if(!done)
            preCompute();
        int n = nums.size();
        int ans = 0;
        for(int &i : nums)
            if(count[i] == 4)
                ans += sum[i];
        return ans;
    }
};