class Solution {
public:
    void solve(int i, int n, int k, string &curr, vector <string> &ans)
    {
        if(ans.size() == k) // we can stop after generating k strings.
            return;

        if(i == n) // Base case.
        {
            ans.push_back(curr);
            return;
        }

        char c = curr.back(); // extract the current character.
        for(int j = 0; j < 3; j++)
        {
            // Recursive call on different character only.
            if(c != (char)('a' + j))
            {
                curr += (char)('a' + j);
                solve(i+1, n, k, curr, ans);
                curr.pop_back();
            }
        }
    }
    string getHappyString(int n, int k)
    {
        vector <string> ans;
        string curr = "";

        // Base function call.
        for(int i = 0; i < 3; i++)
        {
            curr += (char)('a' + i);
            solve(1, n, k, curr, ans);
            curr.pop_back();
        }
        
        // The generated strings will automatically be in lexi-order.
        return ans.size() == k? ans.back(): "";
    }
};