class Solution {
public:
    int solve(int i, int n, int &curr, unordered_set <int> &lookUp)
    {
        if(i == n) // Base case.
        {
            // if current interger is not in given nums the return it since it can be answer.
            if(lookUp.find(curr) == lookUp.end())
                return curr;
            return -1;
        }

        // Add a '0' in binary.
        curr <<= 1;
        int tmp1 = solve(i+1, n, curr, lookUp);
        curr >>= 1; // de-Update to backtrack.

        // Add a '1' in binary.
        curr <<= 1; curr |= 1;
        int tmp2 = solve(i+1, n, curr, lookUp);
        curr >>= 1; // de-Update to backtrack.

        if(tmp1 != -1) 
            return tmp1;
        return tmp2;
    }

    string findDifferentBinaryString(vector<string>& nums)
    {
        int n = nums.size();

        // Create Hash Set to perform instant lookUps.
        unordered_set <int> lookUp;

        // Convert all binary strings to their decimal form and insert into hashset.
        for(string &s : nums)
            lookUp.insert(stoi(s, nullptr, 2));

        int curr = 0;
        int ans = solve(0, n, curr, lookUp);
        
        // Convert the returned interger back to a binary string of length n.
        string res = "";
        while(ans > 0 || n)
        {
            res += ('0' + (ans&1));
            ans >>= 1;
            n--;
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};