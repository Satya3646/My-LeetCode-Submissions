class Solution {
public:
    string decodeCiphertext(string &encodedText, int rows)
    {
        int n = encodedText.size();
        int cols = n / rows;
        
        string ans = "";
        for(int i = 0; i < cols; i++)
        {
            int r = i / cols, c = i % cols;
            while(r < rows && c < cols)
            {
                ans += encodedText[r * cols + c];
                r++;
                c++;
            }
        }

        while(!ans.empty() && ans.back() == ' ')
            ans.pop_back();

        return ans;
    }
};