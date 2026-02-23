/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        // empty tree can't give any targetSum.
        if(!root) 
            return false;

        // If current node is a leaf, then if its value is equal to targetSum, its valid path.
        if(!root->left && !root->right)
            return root->val == targetSum;

        // check if left subtree or right subtree have path with sum = targetSum - root->val.
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};