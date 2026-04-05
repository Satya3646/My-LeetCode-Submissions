class Solution {
public:
    bool judgeCircle(string &moves)
    {
        int cnt[4] = {0, 0, 0, 0};
        for(char c : moves)
        {
            if(c == 'L')
                cnt[0]++;
            else if(c == 'R')
                cnt[1]++;
            else if(c == 'U')
                cnt[2]++;
            else 
                cnt[3]++;
        }

        // for the robo to return to initial position all moves must have their opposite moves.
        return cnt[0] == cnt[1] && cnt[2] == cnt[3];
    }
};