/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr;
        if(root == p || root == q) // Current node is one of target to return the current node since it will backtrack to find the LCA.
            return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q); // Search the left subtree.
        TreeNode* r = lowestCommonAncestor(root->right, p, q); // Search the right subtree.
        if(l && r) // If both searches resulted in a node then current node is the LCA.
            return root;
        if(l) // If only left subtree resulted in a node then both p & q are in left subtree only hence return 'l'.
            return l;
        return r; // If right subtree has p & q or both null case return the 'r'.
    }
};