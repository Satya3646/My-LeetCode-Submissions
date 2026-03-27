const int mod = 12345;

class Solution {
public:
    vector <vector <int>> constructProductMatrix(vector <vector <int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector <vector <int>> ans(n, vector <int> (m, 1));

        long long prefixProd = grid[0][0];
        for(int i = 1; i < (m * n); i++)
        {
            int r = i / m, c = i % m;
            ans[r][c] = (prefixProd % mod);
            prefixProd = ((prefixProd % mod) * (grid[r][c] % mod)) % mod;
        }

        long long suffixProd = grid[n-1][m-1];
        for(int i = (m * n) - 2; i >= 0; i--)
        {
            int r = i / m, c = i % m;
            ans[r][c] = ((ans[r][c] % mod) * (suffixProd % mod)) % mod;
            suffixProd = ((suffixProd % mod) * (grid[r][c] % mod)) % mod;
        }

        return ans;
    }
};