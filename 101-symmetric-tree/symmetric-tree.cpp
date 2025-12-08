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
    bool solve(TreeNode* left, TreeNode* right) // Function to check if two trees are mirrors of each other or not.
    {
        if(left && right)
        {
            if(left->val != right->val)
                return false;
            /* 
            if two trees are to be called mirror images of eachother, left subtree of tree1 and 
            right subtree of tree2 must be mirrors and right subtree of tree1 and left subtree of 
            tree2 must also be mirrors.
            */
            return solve(left->left, right->right) && 
                   solve(left->right, right->left);
        }
        return left == right;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return solve(root->left, root->right);
    }
};