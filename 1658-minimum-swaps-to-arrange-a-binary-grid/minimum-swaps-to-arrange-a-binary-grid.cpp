// class Solution {
// public:
//     int getTrailingZeros(vector <int> &v)
//     {
//         int i = v.size()-1;
//         while(i >= 0 && v[i] == 0)
//             i--;
//         return v.size()-i-1;
//     }

//     int minSwaps(vector<vector<int>>& grid) {
//         int n = grid.size();

//         vector <int> trailing_zeros;
//         for(vector <int> &v : grid)
//             trailing_zeros.push_back(getTrailingZeros(v));

//         int swaps = 0;
//         for(int i = 0; i < n; i++)
//         {
//             int maxIndx = i;
//             for(int j = 0; j < n; j++)
//             {
//                 if(trailing_zeros[j] > trailing_zeros[maxIndx])
//                     maxIndx = j;
//             }

//             if(trailing_zeros[maxIndx] < n-i-1)
//                 return -1;

//             swaps += maxIndx-i;
//         }

//         return swaps;
//     }
// };
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> mexi(grid.size()); // to store the farthest one in that index corresponding to rows in grids
        for(int i=0;i<grid.size();i++)
        {
            int farth=0; // find farthest
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                farth=j;
            }
            mexi[i]=farth;
        }
        int count=0; //count number of steps
        for(int i=0;i<mexi.size();i++)
        {
            if(mexi[i]<=i) // if the current is accepted then move forward
            continue;

            int needed=i; // the maximum needed for mexi[i] position is i

            int j=i+1; // we search for answers from next locations
            while(j<mexi.size() && mexi[j]>needed) //go one find the one where mexi[i] <= needed
            j++;

            if(j==mexi.size()) // if we reach the end while finding then answer not present so return -1
            return -1;

            while(j>i) // now go on swapping from the found location till i and increase count
            {
                swap(mexi[j],mexi[j-1]);
                count++;
                j--;
            }
        }
        return count;
    }
};