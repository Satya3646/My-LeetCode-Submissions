class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int cy = 0;
        
        while(!a.empty() && !b.empty())
        {
            int sum = (a.back() - '0') + (b.back() - '0') + cy;
            res += (char)('0' + sum % 2);
            cy = (sum > 1);
            a.pop_back();
            b.pop_back();
        }
        while(!a.empty())
        {
            int sum = (a.back() - '0') + cy;
            res += (char)('0' + sum % 2);
            cy = (sum > 1);
            a.pop_back();
        }
        while(!b.empty())
        {
            int sum = (b.back() - '0') + cy;
            res += (char)('0' + sum % 2);
            cy = (sum > 1);
            b.pop_back();
        }
        if(cy)
            res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};