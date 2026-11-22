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

    int dfs(TreeNode* root, int max_seen) {
        if (!root) return 0;
        int counter = 0;
        if (root -> val >= max_seen) {
            counter++;
            max_seen = root->val;
        }
        if (root->left) counter += dfs(root->left, max_seen);
        if (root->right) counter += dfs(root->right, max_seen);
        return counter;
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
        
    }
};
