class Solution {
public:
    vector <int> survivedRobotsHealths(vector <int> &positions, 
                                       vector <int> &healths, 
                                       string directions) 
    {
        int n = positions.size();

        vector <int> indx(n);
        iota(indx.begin(), indx.end(), 0);

        sort(indx.begin(), indx.end(), [&positions](int a, int b)
        {
            return positions[a] < positions[b];
        });

        vector <int> stk;
        for(int i = 0; i < n; i++)
        {
            int curr = indx[i];
            if(directions[curr] == 'R')
                stk.push_back(curr);
            else
            {
                while(!stk.empty() && healths[curr] > 0)
                {
                    int top = stk.back();
                    if(healths[curr] > healths[top])
                    {
                        healths[top] = -1;
                        healths[curr]--;
                        stk.pop_back();
                    }
                    else if(healths[curr] < healths[top])
                    {
                        healths[top]--;
                        healths[curr] = -1;
                    }
                    else
                    {
                        healths[curr] = -1;
                        healths[top] = -1;
                        stk.pop_back();
                    }
                }

            }
        }

        vector <int> ans;
        for(int i : healths)
            if(i != -1)
                ans.push_back(i);

        return ans;
    }
};