class Solution {
public:
    string convertToTitle(int columnNumber) {
        string title = "";

        while(columnNumber)
        {
            columnNumber--;
            title += (char)('A' + (columnNumber % 26));
            columnNumber /= 26;
        }
        
        reverse(title.begin(), title.end());
        return title;
    }
};