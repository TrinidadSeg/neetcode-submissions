class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> in(numCourses);
        queue<int> nodes;
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            in[prerequisites[i][0]]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) nodes.push(i);
        }
        while (!nodes.empty()) {
            int node = nodes.front();
            nodes.pop();
            for (int i: adj[node]) {
                in[i]--;
                if (in[i] <= 0) nodes.push(i);
            }
        }
        for (int i: in) if (i) return false;
        return true;
    }
};
