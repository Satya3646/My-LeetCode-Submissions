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
    // void dfs(TreeNode* root, int &ans)
    // {
    //     if(!root)
    //         return;
    //     ans++;
    //     dfs(root->left, ans);
    //     dfs(root->right, ans);
    // }

    // int countNodes(TreeNode* root) {
    //     if(!root)
    //         return 0;
    //     int ans = 0;
    //     dfs(root, ans);
    //     return ans;
    // }

    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int lh = 0, rh = 0;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        while(l)
            l = l->left,
            lh++;
        while(r)
            r = r->left,
            rh++;
        if(lh == rh)
            return 1 + (pow(2, lh)-1) + countNodes(root->right);
        if(lh > rh)
            return 1 + countNodes(root->left) + (pow(2, rh)-1);
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};