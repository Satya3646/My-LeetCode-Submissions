class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end());
        long long totalHappiness = 0;
        for(int i = n-1; i >= 0 && k--; i--)
            totalHappiness += max(0, happiness[i] - (n-i-1));
        return totalHappiness;
    }
};