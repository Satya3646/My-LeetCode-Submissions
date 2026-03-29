class Solution {
public:
    bool canBeEqual(string s, string t)
    {
        if(s[0] != t[0])
            swap(t[0], t[2]);
        
        if(s[1] != t[1])
            swap(t[1], t[3]);
        
        return s == t;
    }
};