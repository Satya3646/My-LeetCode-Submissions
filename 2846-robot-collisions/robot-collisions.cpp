class Solution {
public:
    void merge(int low, int mid, int high,
                vector <int> &positions,
                vector <pair <int, int>> &robots)
    {
        vector <pair <int, int>> tmpRobot;
        vector <int> tmpPos;

        int left = low, right = mid + 1;
        while(left <= mid && right <= high)
        {
            if(positions[left] <= positions[right])
            {
                tmpPos.push_back(positions[left]);
                tmpRobot.push_back(robots[left++]);
            }
            else
            {
                tmpPos.push_back(positions[right]);
                tmpRobot.push_back(robots[right++]);
            }
        }

        while(left <= mid)
        {
            tmpPos.push_back(positions[left]);
            tmpRobot.push_back(robots[left++]);
        }

        while(right <= high)
        {
            tmpPos.push_back(positions[right]);
            tmpRobot.push_back(robots[right++]);
        }

        for(int i = low; i <= high; i++)
        {
            positions[i] = tmpPos[i-low];
            robots[i] = tmpRobot[i-low];
        }
    }

    void mergeSort(int low, int high, 
                   vector <int> &positions,
                   vector <pair <int, int>> &robots)
    {
        if(low >= high)
            return;

        int mid = low + ((high - low) >> 1);
        mergeSort(low, mid, positions, robots);
        mergeSort(mid+1, high, positions, robots);

        merge(low, mid, high, positions, robots);
    }

    vector <int> survivedRobotsHealths(vector <int> &positions, 
                                       vector <int> &healths, 
                                       string &directions) 
    {
        int n = positions.size();


        vector <pair <int, int>> robots(n);
        for(int i = 0; i < n; i++)
            robots[i] = make_pair(healths[i] * ((directions[i] == 'R') - (directions[i] == 'L')), i);
        mergeSort(0, n-1, positions, robots);

        vector <pair <int, int>> tmp;
        int i = 0;
        while(i < n && robots[i].first < 0)
        {
            tmp.push_back(make_pair(-robots[i].first, robots[i].second));
            i++;
        }

        stack <pair <int, int>> stk;
        while(i < n)
        {
            auto [hp, originalPos] = robots[i];

            if(hp > 0)
                stk.push(robots[i]);
            else // left going robot collides with right going robots in the stack.
            {
                hp = -hp;
                // collide as long as left robot has higher health.
                while(!stk.empty() && hp > stk.top().first)
                {
                    hp--;
                    stk.pop();
                }

                if(stk.empty()) // current robot killed all robots in the stack.
                    tmp.push_back(make_pair(hp, originalPos));
                else if(hp == stk.top().first) // both robots kill each other.
                    stk.pop();
                else // robot on top of stack killed current robot.
                    stk.top().first--;
            }

            i++;
        }

        while(!stk.empty())
        {
            tmp.push_back(stk.top());
            stk.pop();
        }

        sort(tmp.begin(), tmp.end(), [](pair <int, int> &a, pair <int, int> &b)
        {
            return a.second < b.second;
        });

        vector <int> ans;
        for(auto [hp, pos] : tmp)
            ans.push_back(hp);

        return ans;
    }
};