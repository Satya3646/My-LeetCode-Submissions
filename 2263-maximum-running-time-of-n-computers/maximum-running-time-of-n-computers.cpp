class Solution {
public:
    bool check(long long mid, int n, vector <int> &batteries)
    {
        // Energy needed to run n computer for mid time = n * mid
        // Energy contribution from the batteries is as follows : 
        // if battery >= time ---> contribution = time
        // if battery < time ---> contribution = battery
        // Sum up all the contributions and see if required power is there or not 
        long long contribution = 0;
        for(int i : batteries)
        {
            contribution += min(1LL * i, mid);
            if(contribution >= n * mid)
                return true;
        }
        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        // There can be more batteries than there are the computers, hence even if a smaller battery dies there will be another extra battery we can use.
        // The trick here is to identify the low and high from the constraints
        // Here we are searching for the max time a conputers can run so, low, high and mid represent time
        // Low is 1, if n = 1 and batteries = 1
        // High is sum(batteries) / n, since the max time we can run n computers using the batteries is     sum (batteries) / n, when we assume all the batteries as single battery with power sum(batteries), then the consumption rate is n since there are n computers, hence the runtime = power / consumption rate.
        long long sum = 0;
        for(int i : batteries)
            sum += i;
        long long low = 0;
        long long high = sum / n;
        long long mid = 0;
        while(low <= high)
        {
            mid = low + ((high - low) >> 1);
            if(check(mid, n, batteries))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};