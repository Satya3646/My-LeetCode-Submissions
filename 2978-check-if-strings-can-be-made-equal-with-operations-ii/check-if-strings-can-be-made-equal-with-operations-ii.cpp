class Solution {
public:
    bool checkStrings(string s, string t)
    {
        int n = s.size();

        unordered_map <char, int> even, odd;
        even.reserve(n/2 + 1);
        odd.reserve(n/2 + 1);

        for(int i = 0; i < n; i++)
        {
            if(i & 1)
                odd[s[i]]++;
            else
                even[s[i]]++;
        }

        for(int i = 0; i < n; i++)
        {
            if(i & 1)
            {
                auto it = odd.find(t[i]);
                if(it == odd.end())
                    return false;
                if(--(it->second) == 0)
                    odd.erase(it);
            }
            else
            {
                auto it = even.find(t[i]);
                if(it == even.end())
                    return false;
                if(--(it->second) == 0)
                    even.erase(it);
            }
        }

        return true;
    }
};