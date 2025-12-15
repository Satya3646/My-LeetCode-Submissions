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
    bool isValidBST(TreeNode* root, long long l = LLONG_MIN, long long r = LLONG_MAX)
    {
        if(!root)
            return true;
        if(l >= root->val || root->val >= r)
            return false;
        return isValidBST(root->left, l, root->val) && isValidBST(root->right, root->val, r);
    }
};