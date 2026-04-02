class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size() ;

        vector<vector<int>> dp(n,vector<int>(3,0)) ;
        
        for(int i = m-1 ; i >= 0 ; i--) {
            for(int j = n-1 ; j >= 0 ; j--) {
                int val = coins[i][j] ; // j
                if(i == m-1 && j == n-1) {
                    dp[j][0] = max(val,0) ;
                    dp[j][1] = max(val,0) ;
                    dp[j][2] = val ;
                    continue ;
                }
                vector<int> d(3,INT_MIN), r(3,INT_MIN) ;

                if(j+1 < n) {
                    r[0] = max(dp[j+1][0]+val,dp[j+1][1]) ;
                    r[1] = max(dp[j+1][1]+val,dp[j+1][2]) ;
                    r[2] = dp[j+1][2]+val ;
                }

                if(i+1 < m) {
                    d[0] = max(dp[j][0]+val,dp[j][1]) ;
                    d[1] = max(dp[j][1]+val,dp[j][2]) ;
                    d[2] = dp[j][2]+val ;
                }

                for(int k = 0 ; k < 3 ; k++) dp[j][k] = max(r[k], d[k]) ;
            }
        }
        
        return dp[0][0] ;
    }
};