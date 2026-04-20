class Solution {
public:
    int findLB(int val, vector <int> &arr, int low, int high)
    {
        while(low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if(arr[mid] >= val)
                low = mid+1;
            else
                high = mid-1;
        }

        return high;
    }

    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int maxDist = 0;
        for(int i = 0; i < n; i++)
        {
            int j = findLB(nums1[i], nums2, i, m-1);
            maxDist = max(maxDist, j - i);
        }

        return maxDist;
    }
};