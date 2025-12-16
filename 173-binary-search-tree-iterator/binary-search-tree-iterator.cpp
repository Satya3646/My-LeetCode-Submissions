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
class BSTIterator {
    stack <TreeNode*> stk; // Imitate the recursion stack.
public:
    BSTIterator(TreeNode* root) {
        TreeNode* curr = root;
        while(curr) // Go deep left pushing the nodes in the way.
            stk.push(curr),
            curr = curr->left;
    }
    
    int next() {
        TreeNode* node = stk.top(); // Extract the top node.
        stk.pop();
        // If the extracted node has a right subtree then go right then go deep left.
        TreeNode* curr = node->right; 
        while(curr)
            stk.push(curr),
            curr = curr->left;
        return node->val;
    }
    
    bool hasNext() {
        return !stk.empty();// If the stack is not empty that means there are nodes to be explored.
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */