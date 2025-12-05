class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int rSum = accumulate(nums.begin(), nums.end(), 0); // Sum or right partition
        int lSum = 0; // Sum of left partition
        int ans = 0;
        // Loop from 0 to n-1, the whole array cant be left partition as per the question.
        // According to the question a partition can only be made between any two elements and not at end of the array.
        for(int i = 0; i < n-1; i++) 
        {
            lSum += nums[i]; // Update lsum
            rSum -= nums[i]; // Update rsum
            if(abs(lSum - rSum) & 1) // If their difference is odd then skip the answer update
                continue;
            ans++; // Answer will get updated if the difference is even
        }
        return ans;
    }
};