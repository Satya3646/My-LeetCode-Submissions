class Solution {
public:
    int dist(int a, int b) {
        if (a == 26) return 0;
        int r1 = a / 6, c1 = a % 6;
        int r2 = b / 6, c2 = b % 6;
        return abs(r1 - r2) + abs(c1 - c2);
    }

    int minimumDistance(string word) {
        int n = word.size();
        vector<vector<int>> dp(n, vector<int>(27, 1e9));

        dp[0][26] = 0;

        for (int i = 1; i < n; i++) {
            int prev = word[i - 1] - 'A';
            int curr = word[i] - 'A';

            for (int other = 0; other <= 26; other++) {
                if (dp[i - 1][other] == 1e9) continue;

                dp[i][other] = min(dp[i][other], dp[i - 1][other] + dist(prev, curr));

                dp[i][prev] = min(dp[i][prev], dp[i - 1][other] + dist(other, curr));
            }
        }

        int result = 1e9;
        for (int j = 0; j <= 26; j++) {
            result = min(result, dp[n - 1][j]);
        }

        return result;
    }
};