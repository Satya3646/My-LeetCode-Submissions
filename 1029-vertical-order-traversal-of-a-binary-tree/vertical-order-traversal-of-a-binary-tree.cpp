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
    void dfs(TreeNode* root, int x, int y, map <int, map<int, multiset <int>>> &mp)
    {
        if(!root)
            return;
        mp[x][y].insert(root->val); // Insert the node into the mapping.
        dfs(root->left, x-1, y+1, mp); // Left --> -1, +1
        dfs(root->right, x+1, y+1, mp); // Right --> +1, +1
    }

    vector <vector <int>> verticalTraversal(TreeNode* root) {
        vector <vector <int>> ans;
        if(!root) 
            return ans;
        // We need mapping from (x, y) pair to set of nodes sorted in order.
        map <int, map<int, multiset <int>>> mp;
        /*
        x defines the column, y defines tree depth of the node.
        We first need to group the nodes based on their x values.
        Then based in their y values since if two nodes have same a and y values then we 
        need to sort them based on values.
        */
        dfs(root, 0, 0, mp);
        for(auto &i : mp) // Iterate over the nodes grouped based on x values.
        {
            vector <int> tmp; // Store the nodes with same x value.
            for(auto &j : i.second) // Iterate over the node grouped (in order) with y values
                tmp.insert(tmp.end(), j.second.begin(), j.second.end()); // Insert the sorted range into the vector.
            ans.push_back(move(tmp)); // Move the group with same x value into the answer.
        }
        return ans;
    }
};