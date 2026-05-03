class Solution {
public:
    int maxDistinct(string &s)
    {
        unordered_set <char> unq;
        for(char c : s)
            unq.insert(c);
        return unq.size();
    }
};