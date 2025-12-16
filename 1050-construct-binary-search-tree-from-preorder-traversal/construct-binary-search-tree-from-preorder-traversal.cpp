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
    int indx = 0;
    TreeNode* bstFromPreorder(vector <int> &preorder, int bound = INT_MAX)
    {
        if(indx == preorder.size() || preorder[indx] > bound)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[indx++]);
        root->left = bstFromPreorder(preorder, root->val);
        root->right = bstFromPreorder(preorder, bound);
        return root;
    }
};