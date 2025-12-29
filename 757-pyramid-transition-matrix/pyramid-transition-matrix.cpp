// const string top = "ABCDEF";

// class Solution {
// public:
//     bool solve(string bottom, vector<string>& allowed, unordered_set <string> &lookUp)
//     {
//         string curr = "";
//         for(int i = 1; i < n; i++)
//         {
//             for(int j = 0; j < 6; j++)
//             {
//                 if(lookUp.find(bottom[i-1] + bottom[i] + top[j]))
//             }
//         }
//     }

//     bool pyramidTransition(string bottom, vector<string>& allowed) {
//         unordered_set <string> lookUp(allowed.begin(), allowed.end());
        
//     }
// };
class Solution {
public:
  bool solve(string bottom, string curr, int i, int j,
           unordered_map<string,int>& mp,
           unordered_map<string,bool>& dp) {

    // pyramid completed
    if (i ==0) return true;

    // memoize only at row start
    if (curr.empty() && dp.count(bottom))
        return dp[bottom];

    // move to upper level
    if (curr.size() == i - 1) {
        bool res = solve(curr, "", i - 1, 0, mp, dp);
        dp[bottom] = res;
        return res;
    }

    for (int k = 0; k < 6; k++) {
        char c = 'A' + k;
        string pattern;
        pattern += bottom[j];
        pattern += bottom[j + 1];
        pattern += c;

        if (mp.count(pattern)) {
            if (solve(bottom, curr + c, i, j + 1, mp, dp))
                return true;
        }
    }

    return false;
}

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, int> mp;
        for (auto i : allowed) {
            mp[i]++;
        }
        unordered_map<string, bool> dp;
        return solve(bottom, "", bottom.size(), 0, mp,dp);
    }
};