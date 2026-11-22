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

    int runMax;

    int maxSum(TreeNode* root) {
        int total = root -> val;
        int l = 0;
        int r = 0;
        if (root -> right) {
            l = max(maxSum(root->right), 0);
        }
        if (root -> left) {
            r = max(maxSum(root->left), 0);
        }
        runMax = max(runMax, l + r + total);
        return total + max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        runMax = INT_MIN;
        maxSum(root);
        return runMax;
    }
};
