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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> bfs;
        vector<int> ans;
        bfs.push(root);
        while (!bfs.empty()) {
            int reps = bfs.size();
            int val = 0;
            int seen = 0;
            for (int i = 0; i < reps; i++) {
                TreeNode* dummy = bfs.front();
                bfs.pop();
                if (!dummy) continue;
                seen = 1;
                val = dummy->val;
                if (dummy->left) bfs.push(dummy->left);
                if (dummy->right) bfs.push(dummy->right);
            }
            if (seen) ans.push_back(val);
        }
        return ans;
    }
};
