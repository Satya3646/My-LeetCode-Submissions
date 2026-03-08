class Solution {
public:
    int solve(int i, int n, int &curr, unordered_set <int> &lookUp)
    {
        if(i == n)
        {
            if(lookUp.find(curr) == lookUp.end()) 
                return curr;
            return -1;
        }

        curr <<= 1;
        int tmp1 = solve(i+1, n, curr, lookUp);
        curr >>= 1;

        curr >>= 1; curr |= 1;
        int tmp2 = solve(i+1, n, curr, lookUp);
        curr >>= 1;

        if(tmp1 != -1)
            return tmp1;
        return tmp2;
    }

    string findDifferentBinaryString(vector<string>& nums)
    {
        int n = nums.size();
        unordered_set <int> lookUp;
        for(string &s : nums)
            lookUp.insert(stoi(s, nullptr, 2));
        int curr = 0;
        int ans = solve(0, n, curr, lookUp);

        if(ans == -1)
            return "";
        
        string res = "";
        while(ans || n)
        {
            res += ('0' + (ans&1));
            ans >>= 1;
            n--;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};