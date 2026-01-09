class Solution {
public:
    // This function will return the max depth reachable from the given node. 
    int solve(TreeNode* root, int currDepth, TreeNode* &maxNode, int &maxDepth)
    {
        maxDepth = max(maxDepth, currDepth); // maxDepth must be updated before doing any thing.
        if(!root)
            return currDepth;
        // get the max depth reachable from left and right subtrees.
        int l = solve(root->left, currDepth+1, maxNode, maxDepth);
        int r = solve(root->right, currDepth+1, maxNode, maxDepth);
        if(l == maxDepth && r == maxDepth) // if both subtrees can reach deepest parts the root is the answer.
            maxNode = root;
        return max(l, r); // return the deepest depth.
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root)
    {
        TreeNode* maxNode = nullptr;
        int maxDepth = 0;
        solve(root, 0, maxNode, maxDepth);
        return maxNode;
    }
};