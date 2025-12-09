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
    int widthOfBinaryTree(TreeNode* root) {
        /*
        To solve this problem we need the distance between the leftmost non null node to the 
        rightmost non null node of the tree, but during the count we need to even consider the null 
        nodes for the count. 
        Treat each level of the tree as an array. For root the index is 0, for next level the indice
        are 0(left) and 1(right).
                     0 (root)
                   /   \
                  0     1
                 / \   / \
                0   1 2   3
        If we the observe the trend the indexing is following the rule as if x is the index of  
        parent the left child has the index 2x and right child has the index 2x+1.
        */
        queue <pair <TreeNode*, unsigned long long>> q; // Store the node along with its respective index.
        q.push({root, 0});
        unsigned long long ans = 0;
        while(!q.empty())
        {
            int n = q.size();
            unsigned long long l = 0, r = 0; // Capture index of leftmost non null node and rightmost non null node.
            for(int i = 0; i < n; i++)
            {
                TreeNode* node = q.front().first;
                unsigned long long x = q.front().second;
                if(i == 0)
                    l = x;
                if(i == n-1)
                    r = x;
                q.pop();
                if(node->left)
                    q.push({node->left, (x<<1)});
                if(node->right)
                    q.push({node->right, (x<<1)+1});
            }
            ans = max(ans, r-l+1); // Update the ans.
        }
        return ans;
    }
};