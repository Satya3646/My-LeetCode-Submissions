class Solution {
public:
    string generateString(string &str1, string &str2)
    {
        int n = str1.size();
        int m = str2.size();

        string ans(n + m - 1,'*');
        for(int i = 0; i < n; i++)
        {
            if(str1[i] != 'T')
                continue;

            // subtring from i to i+m-1 must be str2.
            for(int j = 0; j < m; j++)
            {
                if(ans[i+j] != '*' && ans[i+j] != str2[j])
                    return "";
                ans[i+j] = str2[j];
            }
        }

        string tmp = ans;
        for(char &c : ans)
            if(c == '*')
                c = 'a';

        for(int i = 0; i < n; i++)
        {
            if(str1[i] != 'F')
                continue;

            // subtring from i to i+m-1 must not be str2.
            if(ans.substr(i, m) != str2)
                continue;

            bool flag = false;
            for(int j = m-1; j >= 0; j--)
            {
                if(tmp[i+j] == '*')
                {
                    ans[i+j] = 'b';
                    flag = true;
                    break;
                }
            }

            if(!flag) // could not make them unequal.
                return "";
        }

        return ans;
    }
};