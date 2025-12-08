class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for(int a = 1; a <= n; a++)
        {
            for(int b = 1; b <= n; b++)
            {
                int c_2 = a*a + b*b;
                int c = ceil(sqrt(c_2));
                if((c_2 == c*c) && (c <= n))
                    cnt++;
            }
        }
        return cnt;
    }
};