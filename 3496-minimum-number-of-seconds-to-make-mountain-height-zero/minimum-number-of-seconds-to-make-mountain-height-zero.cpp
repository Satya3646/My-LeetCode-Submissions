class Solution {
public:
    bool canReduceMountain(long long mid, int mountainHeight, vector <int> &workerTimes)
    {
        for(int i : workerTimes)
        {
            mountainHeight -= (int)(-0.5 + sqrt(0.25 + 2.0 * (double)(mid / i)));

            if(mountainHeight <= 0)
                return true;
        }

        return mountainHeight <= 0;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes)
    {
        long long low = 1, high = 1e18;
        while(low <= high)
        {
            long long mid = low + ((high - low) >> 1);
            if(canReduceMountain(mid, mountainHeight, workerTimes))
                high = mid-1;
            else
                low = mid+1;
        }

        return low;
    }
};