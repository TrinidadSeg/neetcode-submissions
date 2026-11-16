class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> dependencies(numCourses);
        vector<int> in(numCourses);
        for (vector<int> prereq: prerequisites) {
            dependencies[prereq[1]].push_back(prereq[0]);
            in[prereq[0]]++;
        }
        queue<int> nodes;
        vector<int> path;
        for (int i = 0; i < numCourses; i++) if (!in[i]) nodes.push(i);
        while (!nodes.empty()) {
            int node = nodes.front();
            path.push_back(node);
            nodes.pop();
            for (int dep: dependencies[node]) {
                in[dep]--;
                if (!in[dep]) nodes.push(dep);
            }
        }
        for (int i: in) if (i) return {};
        return path;
    }
};
