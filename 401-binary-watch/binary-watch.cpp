class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        if(turnedOn >= 9)
            return {};
        vector <vector <int>> hours(4);
        for(unsigned i = 0; i < 12; i++)
            hours[popcount(i)].push_back(i);

        vector <vector <int>> mins(6);
        for(unsigned i = 0; i < 60; i++)
            mins[popcount(i)].push_back(i);

        vector <string> ans;
        for(int i = 0; i <= turnedOn; i++)
        {
            if(i >= 4 || turnedOn - i >= 6) // cant display.
                continue;
            for(auto h : hours[i])
            {
                string hh = to_string(h);
                int j = turnedOn - i;
                for(auto m : mins[j])
                {
                    string mm = ":";
                    if(m <= 9)
                        mm += '0';
                    mm += to_string(m);
                    ans.push_back(hh + mm);
                }
            }
        }

        return ans;
    }
};