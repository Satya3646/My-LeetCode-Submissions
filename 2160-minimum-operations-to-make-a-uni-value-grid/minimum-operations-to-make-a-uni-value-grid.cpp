class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector <int> arr;
        for(vector <int> &v : grid)
            arr.insert(arr.end(), v.begin(), v.end());

        sort(arr.begin(), arr.end());

        int median = arr[arr.size() / 2];
        int ops = 0;
        for(int i : arr)
        {
            int diff = abs(i - median);
            if(diff % x != 0)
                return -1;
            
            ops += diff / x;
        }

        return ops;
    }
};