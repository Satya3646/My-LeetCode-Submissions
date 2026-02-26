class Solution {
public:
    int titleToNumber(string &columnTitle)
    {
        int n = columnTitle.size();
        long long columnNumber = 0;
        for(int i = 0; i < n; i++)
            columnNumber = columnNumber * 26 + (columnTitle[i] - 'A' + 1);
        return columnNumber;
    }
};