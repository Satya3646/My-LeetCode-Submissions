class Solution {
public:
    bool isTrionic(vector<int>& nums)
    {
        int n = nums.size();
        int start, i;

        start = i = 1;
        // Scan for increasing part.
        while(i < n && nums[i] > nums[i-1]) 
            i++;
        // i has not moved --> No increasing part, 1st condition fail.
        // i has reached end --> 2nd and 3rd conditions fail.
        if(i == start || i == n)
            return false;
            
        start = i;
        // Scan for decreasing part.
        while(i < n && nums[i] < nums[i-1])
            i++;
        // i has not moved --> No decreasing part, 2nd condition fail.
        // i has reached end --> 3rd condition fail.
        if(start == i || i == n)
            return false;

        start = i;
        // Scan for increasing part.
        while(i < n && nums[i] > nums[i-1])
            i++;
        // i has not moved --> No increasing part, 3rd condition fail.
        if(i == start) 
            return false;
        return i == n;
    }
};