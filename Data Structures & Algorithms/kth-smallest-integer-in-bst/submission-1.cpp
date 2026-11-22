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

    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> visits;
        TreeNode* cur = root;
        int counter = k;
        while (cur || !visits.empty()) {
            while (cur) {
                visits.push(cur);
                cur = cur-> left;
            }
            cur = visits.top();
            visits.pop();
            if (!--counter) return cur->val;
            cur = cur -> right;
        }
        return 0;
        
    }
};
