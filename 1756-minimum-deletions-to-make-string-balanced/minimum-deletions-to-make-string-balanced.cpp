class Solution {
public:
    int minimumDeletions(string s)
    {
        int res = 0, cnt = 0;
        for(char c : s)
        {
            if(c == 'b') // if 'b' is encountered the increment.
                cnt++;
            // if 'a' is encountered and previous 'b' cnt is +ve the we need to delete that 'b'.
            else if(cnt) 
            {
                res++; // increment deletions.
                cnt--; // decremnt b count since we deleted it.
            }
        }
        return res;
    }
};