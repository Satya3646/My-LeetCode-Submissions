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
    int solve(TreeNode *root, int &dia)
    {
        if(!root)
            return 0;
        int l = solve(root->left, dia); // Height of the left subtree
        int r = solve(root->right, dia); // Height of the right subtree
        dia = max(dia, l + r); // Update diameter
        return 1 + max(l, r); // return height till now
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        solve(root, dia); // Call function to calculate the diamater as we calculate the height
        return dia;
    }
};