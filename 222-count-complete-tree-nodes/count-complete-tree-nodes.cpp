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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int lh = 0, rh = 0; // Depth of the left and right subtrees
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        while(l)
            l = l->left,
            lh++;
        while(r)
            r = r->left,
            rh++;
        if(lh == rh) // If left subtree and right subtree have same depth then left subtree is guaranteed to be complete hence get n for left tree as 2^lh - 1 and traverse the right subtree.
            return 1 + ((1 << lh)-1) + countNodes(root->right);
        if(lh > rh) // If left depth is more than the right depth that means right subtree is guaranteed to be complete hence get n for right tree as 2^rh - 1 and traverse left subtree.
            return 1 + countNodes(root->left) + ((1 << rh)-1);
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};