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
    int height(TreeNode *root)
    {
        if(!root)
            return 0;
        int left = height(root->left); // Get height of left subtree
        int right = height(root->right); // Get the height of the right subtree
        if(left == -1 || right == -1) // If either is unbalanced then return -1 as a failure signal
            return -1;
        if(abs(left - right) > 1) // If the current root is unbalanced the return -1 as a failure signal
            return -1;
        return 1 + max(left, right); // If all above cases fail then return the height till current node from the bottom
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1; // Get the height of the tree, if -1 is returned then balance failed at some node so return false else return true
    }
};