class Solution {
public:
    TreeNode* merge(vector <int> &nums, int left, int right)
    {
        if(left > right) // Base case.
            return nullptr;

        int mid = left + ((right - left) >> 1);
        TreeNode* root = new TreeNode(nums[mid]); // Create root node.
        
        root->left = merge(nums, left, mid-1); // build and attach left subtree.
        root->right = merge(nums, mid+1, right); // build and attach right subtree.

        return root; // ruturn the tree.
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Think of solution based on merge sort.
        // Middle element is root the left part will become 
        // the left subtree and right past --> right subtree.
        return merge(nums, 0, nums.size()-1);
    }
};