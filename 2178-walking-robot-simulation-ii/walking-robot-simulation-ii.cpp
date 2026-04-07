class Robot {
    int x, y;
    char dir;
    int perimeter;
    int m, n;

private:
    void rotateLeft(char &dir)
    {
        if(dir == 'E')
            dir =  'N';
        else if(dir == 'N')
            dir = 'W';
        else if(dir == 'W')
            dir = 'S';
        else if(dir == 'S')
            dir = 'E';
    }

public:
    Robot(int width, int height)
    {
        x = y = 0;
        dir = 'E';
        perimeter = 2*width + 2*height - 4;
        m = width;
        n = height;
    }
    
    void step(int num)
    {
        num %= perimeter;
        if(num == 0)
            num = perimeter;
         
        while(num > 0)
        {
            if(dir == 'E')
            {
                int nx = min(x + num, m - 1);
                num -= (nx - x);
                x = nx;
                if(num != 0)
                    dir = 'N';
            }
            else if(dir == 'W')
            {
                int nx = max(x - num, 0);
                num -= (x - nx);
                x = nx;
                if(num != 0)
                    dir = 'S';
            }
            else if(dir == 'N')
            {
                int ny = min(y + num, n - 1);
                num -= (ny - y);
                y = ny;
                if(num != 0)
                    dir = 'W';
            }
            else if(dir == 'S')
            {
                int ny = max(y - num, 0);
                num -= (y - ny);
                y = ny;
                if(num != 0)
                    dir = 'E';
            }
        }
    }
    
    vector <int> getPos()
    {
        return {x, y};
    }
    
    string getDir()
    {
        if(dir == 'E')
            return "East";
        if(dir == 'W')
            return "West";
        if(dir == 'N')
            return "North";
        return "South";
    }
};

//     N
//     |
// W---|---E
//     |
//     S

/*
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */