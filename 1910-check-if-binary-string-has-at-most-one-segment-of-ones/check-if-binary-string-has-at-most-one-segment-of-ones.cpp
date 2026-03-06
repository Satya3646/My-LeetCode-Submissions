class Solution {
public:
    bool checkOnesSegment(string &s)
    {
        int n = s.size();
        int seg = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')
            {
                seg++;
                while(i < n && s[i] == '1')
                    i++;
            }
        }
        return seg == 1;
    }
};