class Solution {
public:
    int revNum(int n)
    {
        int ans = 0;
        while(n)
        {
            ans = ans * 10 + n % 10;
            n /= 10;
        }

        return ans;
    }

    int minMirrorPairDistance(vector<int>& nums)
    {
        int n = nums.size();
        unordered_map <int, int> mp;
        mp.reserve(n);
        
        int minDist = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            int val = nums[i];
            int rev = revNum(val);
            cout << rev << endl;
            auto it = mp.find(nums[i]);

            if(it != mp.end())
                minDist = min(minDist, i - mp[nums[i]]);

            mp[rev] = i;
        }

        return minDist == INT_MAX? -1: minDist;
    }
};