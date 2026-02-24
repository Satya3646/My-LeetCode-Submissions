class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        vector <int> pascalRow(rowIndex+1);
        pascalRow[0] = 1;
        for(int i = 1; i <= rowIndex; i++)
            pascalRow[i] = (int)(1LL * pascalRow[i-1] * (rowIndex - i + 1) / i);
        return pascalRow;
    }
};