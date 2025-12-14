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
    // Inorder traversal of BST gives the nodes in their sorted so we just make use of it, decrementing k for every nnode we visit and when k becomes zero we just return that node.
    int kthSmallest(TreeNode* root, int &k)
    {
        if(!root)
            return -1;
        int l = kthSmallest(root->left, k);
        if(l != -1)
            return l;
        k--;
        if(k == 0)
            return root->val;
        return kthSmallest(root->right, k);
    }
};