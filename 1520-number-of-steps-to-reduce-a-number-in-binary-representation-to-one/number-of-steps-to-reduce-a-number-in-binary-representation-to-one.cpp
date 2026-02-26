class Solution {
public:
    void addOne(string &s)
    {
        int i = s.size()-1;

        while(i >= 0 && s[i] == '1')
        {
            s[i] = '0';
            i--;
        }

        if(i >= 0)  
            s[i] = '1';
        else 
            s = "1" + s;
    }

    int numSteps(string &s)
    {
        int steps = 0;
        while(s.size() != 1 ||  s[0] != '1')
        {
            steps++;
            if(s.back() == '0')
                s.pop_back();
            else
                addOne(s);
        }
        return steps;
    }
};