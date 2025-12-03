// class Solution {
// public:
//     int countTrapezoids(vector<vector<int>>& points) {
//         int n = points.size();
//         /*
//         To solve this problem we need to diffrentiate points based on the line they are on as well as
//         the slope of the line.
//         First we differentiate the lines baesd on the slope, so now we have lines grouped based on slope
//         But there can be may lines with the same slope value we need to differentiate them too.
//         We use the concept of y-intercept to differentiate the parallel lines.
//         The mapping looks something like the following : 
//         Map (Key: Slope)
//         │
//         ├── Slope {1, 1} (Diagonal 45°)
//         │   │
//         │   ├── Line Constant 0  (e.g., y=x)      -> Count: 3 segments
//         │   ├── Line Constant 5  (e.g., y=x+5)    -> Count: 2 segments
//         │   └── Line Constant -2 (e.g., y=x-2)    -> Count: 1 segment
//         │       ^
//         │       We calculate pairs HERE: (3*2) + (3*1) + (2*1)
//         │
//         ├── Slope {1, 0} (Vertical)
//         │   │
//         │   ├── Line Constant 10 (x=10) -> Count: 4 segments
//         │   └── (No other lines)        -> Count: 0 trapezoids
//         */
//         map <vector <int>, map <int, int>> mp;
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = i+1 ; j < n; j++)
//             {
//                 int dx = points[i][0] - points[j][0];
//                 int dy = points[i][1] - points[j][1];
//                 if(dx < 0 || (dx == 0 && dy < 0))// Maintain correct sign for dx(+ve) & dy(-ve if needed)
//                 {
//                     dx = -dx;
//                     dy = -dy;
//                 }
//                 int g = gcd(abs(dx), abs(dy)); // Normalize to have dx and dy in base fraction form
//                 dx /= g;
//                 dy /= g;
//                 int c = dy * points[i][0] - dx * points[i][1]; // Calculate line constant c = dy*x - dx*y
//                 mp[{dx, dy}][c]++; // Update mapping : slope --> line --> points count
//             }
//         }
//         long long trapezoids = 0; // String the number of trapezoids
//         // Taking any two lines with same slope, different line constants will result in a trapezoids
//         // So calculate the number of trapezoids accordingly
//         for(pair <vector <int>, map <int, int>> slope: mp)
//         {
//             long long sum = 0;
//             for(pair <int, int> p : slope.second)
//             {
//                 trapezoids += sum * p.second;
//                 sum += p.second;
//             } 
//         }
//         // The parallellograms will be counted twice so we need to exclude them
//         // Two non parallel segments having the same midpoints will form a paralellogram so count and
//         // exclude them accordingly.
//         map <vector <int>, int> midpoints; // Keep number of points with same midpoint
//         map <vector <int>, map <vector <int>, int>> directions; // keep number of points with same midpoint but different slopse
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = i+1;j < n; j++)
//             {
//                 int mx = points[i][0] + points[j][0];
//                 int my = points[i][1] + points[j][1];
//                 int dx = points[i][0] - points[j][0];
//                 int dy = points[i][1] - points[j][1];
//                 if(dx < 0 || (dx == 0 && dy < 0))// Maintain correct sign for dx(+ve) & dy(-ve if needed)
//                 {
//                     dx = -dx;
//                     dy = -dy;
//                 }
//                 int g = gcd(abs(dx), abs(dy)); // Normalize to have dx and dy in base fraction form
//                 dx /= g;
//                 dy /= g;
//                 if(midpoints.find({mx, my}) != midpoints.end())
//                     trapezoids -= (midpoints[{mx, my}] - directions[{mx, my}][{dx, dy}]);
//                 midpoints[{mx, my}]++;
//                 directions[{mx, my}][{dx, dy}]++;
//             }
//         }
//         return trapezoids;
//     }
// };
class Solution {
public:
    long long key(int x, int y) {
        // pack (x, y) into 64 bits
        return ( (long long)x << 32 ) ^ (unsigned int)y;
    }

    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();

        // map <vector <int>, map <int, int>> mp;
        // slope -> (line constant c -> count)
        unordered_map<long long, unordered_map<int, int>> mp;

        for(int i = 0; i < n; i++)
        {
            for(int j = i+1 ; j < n; j++)
            {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                if(dx < 0 || (dx == 0 && dy < 0))// Maintain correct sign for dx(+ve) & dy(-ve if needed)
                {
                    dx = -dx;
                    dy = -dy;
                }
                int g = gcd(abs(dx), abs(dy)); // Normalize to have dx and dy in base fraction form
                dx /= g;
                dy /= g;
                int c = dy * points[i][0] - dx * points[i][1]; // Calculate line constant c = dy*x - dx*y
                long long slopeKey = key(dx, dy);
                mp[slopeKey][c]++; // Update mapping : slope --> line --> points count
            }
        }

        long long trapezoids = 0; // Storing the number of trapezoids
        // Taking any two lines with same slope, different line constants will result in a trapezoids
        // So calculate the number of trapezoids accordingly
        for(auto &slope: mp)
        {
            long long sum = 0;
            for(auto &p : slope.second)
            {
                trapezoids += sum * p.second;
                sum += p.second;
            } 
        }

        // The parallellograms will be counted twice so we need to exclude them
        // Two non parallel segments having the same midpoints will form a paralellogram so count and
        // exclude them accordingly.

        // map <vector <int>, int> midpoints;
        // map <vector <int>, map <vector <int>, int>> directions;
        unordered_map<long long, int> midpoints;                          // midpoint -> total segments
        unordered_map<long long, unordered_map<long long, int>> directions; // midpoint -> (direction -> count)

        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                int mx = points[i][0] + points[j][0];
                int my = points[i][1] + points[j][1];
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                if(dx < 0 || (dx == 0 && dy < 0))// Maintain correct sign for dx(+ve) & dy(-ve if needed)
                {
                    dx = -dx;
                    dy = -dy;
                }
                int g = gcd(abs(dx), abs(dy)); // Normalize to have dx and dy in base fraction form
                dx /= g;
                dy /= g;

                long long midKey = key(mx, my);
                long long dirKey = key(dx, dy);

                auto it = midpoints.find(midKey);
                if(it != midpoints.end()) {
                    // subtract only non-parallel diagonals with same midpoint
                    int total = it->second;
                    int same_dir = directions[midKey][dirKey];
                    trapezoids -= (long long)(total - same_dir);
                }

                midpoints[midKey]++;
                directions[midKey][dirKey]++;
            }
        }
        return (int)trapezoids;
    }
};
