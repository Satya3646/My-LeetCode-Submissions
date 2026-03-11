class Solution {
public:
    int bitwiseComplement(int n)
    {
        if(n == 0)
            return 1;

        string s = "";
        while(n)
        {
            s += '0' + (n & 1);
            n >>= 1;
        }

        reverse(s.begin(), s.end());

        for(char &c : s)
        {
            if(c == '1')
                c = '0';
            else
                c = '1';
        }
        
        return stoi(s, nullptr, 2);
    }
};