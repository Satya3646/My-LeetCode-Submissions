class Solution {
public:
    long long getDescentPeriods(vector <int> &prices)
    {
        int n = prices.size();
        long long ans = 0;
        int cnt = 0;
        int i = 0;
        while(i < n)
        {
            int j = i+1; // Right pointer to expand the window.
            while(j < n && prices[j-1] - prices[j] == 1) // Go right as long as smooth descent is there.
                j++;
            int len = j-i; // Get the length of the segment with smooth descent.
            i = j;
            ans += 1LL * len * (len+1) / 2; // Number of subarrays = (n x (n+1))/2.
        }
        return ans;
    }
};