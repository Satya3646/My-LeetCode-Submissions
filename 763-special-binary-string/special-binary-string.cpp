class Solution {
public:
    string makeLargestSpecial(string s)
    {
        int n = s.size();
        int cnt = 0, st = 0;
        vector <string> special;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')
                cnt++;
            else if(s[i] == '0')
                cnt--;
            
            if(cnt == 0) // s[0...i] is a special substring.
            {
                // front is '1' and back is '0', extract the middle part.
                string tmp = s.substr(st+1, i-st-1);
                // now since front and back is fixed, rearrange the middle part for best case.
                tmp = '1' + makeLargestSpecial(tmp) + '0';
                special.push_back(tmp); // push the rearranged string.
                st = i+1;
            }
        }

        // sort the special substrings found in decresing order.
        sort(special.rbegin(), special.rend());
        string ans = "";
        for(string &t : special)
            ans += t;

        return ans;
    }
};