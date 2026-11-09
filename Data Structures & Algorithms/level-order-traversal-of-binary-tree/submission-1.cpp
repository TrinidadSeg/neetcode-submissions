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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> bfs;
        bfs.push(root);
        vector<vector<int>> ans;
        while (!bfs.empty()) {
            int reps = bfs.size();
            vector<int> temp;
            for (int i = 0; i < reps; i++) {
                TreeNode* dummy = bfs.front();
                bfs.pop();
                if (!dummy) continue;
                temp.push_back(dummy->val);
                if (dummy->left) bfs.push(dummy->left);
                if (dummy->right) bfs.push(dummy->right);
            }
            if (temp.size()) ans.push_back(temp);
        }
        return ans;
    }
};
