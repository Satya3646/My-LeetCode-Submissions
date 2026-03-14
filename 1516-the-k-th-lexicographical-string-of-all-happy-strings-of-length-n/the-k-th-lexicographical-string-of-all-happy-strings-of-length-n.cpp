class Solution {
public:
    void solve(int i, int n, int k, string &curr, vector <string> &ans)
    {
        if(ans.size() == k)
            return;

        if(i == n)
        {
            ans.push_back(curr);
            return;
        }

        char c = curr.back();
        if(c != 'a')
        {
            curr += 'a';
            solve(i+1, n, k, curr, ans);
            curr.pop_back();
        }

        if(c != 'b')
        {
            curr += 'b';
            solve(i+1, n, k, curr, ans);
            curr.pop_back();
        }

        if(c != 'c')
        {
            curr += 'c';
            solve(i+1, n, k, curr, ans);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k)
    {
        vector <string> ans;
        string curr = "";
        curr += 'a';
        solve(1, n, k, curr, ans);
        curr.pop_back();
        
        curr += 'b';
        solve(1, n, k, curr, ans);
        curr.pop_back();

        curr += 'c';
        solve(1, n, k, curr, ans);
        curr.pop_back();

        return ans.size() == k? ans.back(): "";
    }
};