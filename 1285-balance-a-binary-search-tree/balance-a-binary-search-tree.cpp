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
    void getInorder(TreeNode* root, vector <int> &nodes)
    {
        if(!root)
            return;
        getInorder(root->left, nodes);
        nodes.push_back(root->val);
        getInorder(root->right, nodes);
    }

    TreeNode* buildBinaryTree(vector <int> nodes, int left, int right)
    {
        if(left > right)
            return nullptr;
        int mid = left + ((right - left) >> 1);
        TreeNode* root = new TreeNode(nodes[mid]);
        root->left = buildBinaryTree(nodes, left, mid-1);
        root->right = buildBinaryTree(nodes, mid+1, right);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root)
    {
        vector <int> nodes;
        getInorder(root, nodes);
        return buildBinaryTree(nodes, 0, nodes.size()-1);
    }
};