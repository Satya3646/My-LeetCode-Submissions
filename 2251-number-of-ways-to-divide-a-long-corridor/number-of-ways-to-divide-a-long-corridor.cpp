const int mod = 1e9+7;

class Solution {
public:
    int numberOfWays(string &corridor) {
        int n = corridor.size();
        int cntSeats = 0;
        long long cnt = 0;
        char c = 'S';
        long long ans = 1;
        int i = 0, j = n-1;
        while(i < j && corridor[i] != 'S')
            i++;
        while(j > i && corridor[j] != 'S')
            j--;
        while(i <= j)
        {
            if(corridor[i] == 'S') // Update count of seats.
                cntSeats++;
            if(c == corridor[i]) // if current item is equal to c increment count.
                cnt++;
            // cout << c << "--->" << cnt << endl;
            if(c == 'S' && cnt == 2)
            {
                c = 'P';
                cnt = 0;
            }
            else if(c == 'P' && corridor[i] == 'S')
            {
                c = 'S';
                ans = ((ans % mod) * ((cnt+1) % mod)) % mod;
                cnt = 1;
            }
            i++;
        }
        return ((cntSeats == 0) || (cntSeats & 1))? 0: ans;
    }
};