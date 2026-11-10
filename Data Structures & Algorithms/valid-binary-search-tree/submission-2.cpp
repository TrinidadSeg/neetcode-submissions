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
    bool helper(TreeNode* root, int min, int max) {
        if (!root) return true;
        if ((root->val <= min) || (root->val >= max)) return false;
        if (root->right) {
            if (!helper(root->right, root->val, max)) return false;
        }
        if (root->left) {
            if (!helper(root->left, min, root->val)) return false;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MIN, INT_MAX);
    }
};
