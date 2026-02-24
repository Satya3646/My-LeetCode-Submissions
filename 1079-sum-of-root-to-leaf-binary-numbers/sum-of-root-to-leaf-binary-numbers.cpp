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
    int help(TreeNode* root, int curr)
    {
        if(!root) // Empty tree.
            return 0;
        
        curr <<= 1; // shift left.
        curr |= root->val; // add the current bit.

        // if current node is a leaf then path ended so return.
        if(!root->left && !root->right) 
            return curr;

        // recursive call on the left and right subtree.
        return help(root->left, curr) +
               help(root->right, curr);
    }

    int sumRootToLeaf(TreeNode* root)
    {
        return help(root, 0);
    }
};