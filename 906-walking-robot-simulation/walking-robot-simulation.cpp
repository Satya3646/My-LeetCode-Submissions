class Solution {
public:
    void rotate90(char &dir, int rot)
    {
        if(rot == -2)
        {
            // A 90-degree left rotation is equivalent to 270-degree right rotation.
            rotate90(dir, -1);
            rotate90(dir, -1);
        }

        if(dir == 'U')
            dir = 'R';
        else if(dir == 'D')
            dir = 'L';
        else if(dir == 'L')
            dir = 'U';
        else if(dir == 'R')
            dir = 'D';
        
        return;
    }

    pair <int, int> updatePos(char dir, int x, int y, int k, set <vector <int>> &s)
    {
        int dx = (dir == 'R') - (dir == 'L');
        int dy = (dir == 'U') - (dir == 'D');

        for(int step = 1; step <= k; step++)
        {
            int nx = x + dx;
            int ny = y + dy;

            if(s.find({nx, ny}) != s.end())
                return {x, y};

            x = nx;
            y = ny;
        }

        return {x, y};
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
    {
        int n = commands.size();
        set <vector <int>> s(obstacles.begin(), obstacles.end());
        char dir = 'U';
        int x = 0, y = 0;
        int maxDist = 0;

        for(int i = 0; i < n; i++)
        {
            if(commands[i] == -1 || commands[i] == -2)
                rotate90(dir, commands[i]);
            else
            {
                tie(x, y) = updatePos(dir, x, y, commands[i], s);
                maxDist = max(maxDist, (x * x) + (y * y));
            }
        }

        return maxDist;
    }
};