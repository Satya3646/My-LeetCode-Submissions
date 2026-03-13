class Solution {
public:
    bool canReduceMountain(long long mid, int mountainHeight, vector <int> &workerTimes)
    {
        for(int i : workerTimes)
        {
            // Reduce the mountain height as much as the worker can in given time(mid).
            mountainHeight -= (int)(-0.5 + sqrt(0.25 + 2.0 * (double)(mid / i)));

            // Short Ckt : If at any point mountain was reduced to 0.
            if(mountainHeight <= 0)
                return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes)
    {
        // Upper and Lower bounds.
        long long low = 1, high = 1e18;
        while(low <= high)
        {
            long long mid = low + ((high - low) >> 1);

            // If mountain can be reduced to 0 the try to find smaller time.
            if(canReduceMountain(mid, mountainHeight, workerTimes))
                high = mid-1;
            else
                low = mid+1;
        }

        return low;
    }
};