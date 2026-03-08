class Solution {
public:
    string solve(int i, int n, string &curr, unordered_set <string> &lookUp)
    {
        if(i == n)
        {
            if(lookUp.find(curr) == lookUp.end()) 
                return curr;
            return "#";
        }

        curr += '0';
        string tmp1 = solve(i+1, n, curr, lookUp);
        curr.pop_back();

        curr += '1';
        string tmp2 = solve(i+1, n, curr, lookUp);
        curr.pop_back();

        if(tmp1 != "#")
            return tmp1;
        return tmp2;
    }

    string findDifferentBinaryString(vector<string>& nums)
    {
        int n = nums.size();
        unordered_set <string> lookUp(nums.begin(), nums.end());
        string curr = "";
        string ans = solve(0, n, curr, lookUp);

        return ans == "#"? "": ans;
    }
};