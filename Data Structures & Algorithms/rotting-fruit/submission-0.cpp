class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> nodes;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) nodes.push({i, j});
            }
        }
        int counter = 0;
        while (!nodes.empty()) {
            int reps = nodes.size();
            bool did = false;
            for (int times = 0; times < reps; times++) {
                pair<int, int> coords = nodes.front();
                nodes.pop();
                for (int i = 0; i < 4; i++) {
                    int y = coords.first + dy[i];
                    int x = coords.second + dx[i];
                    if ((x < 0) || (x >= cols)) continue;
                    if ((y < 0) || (y >= rows)) continue;
                    if (grid[y][x] == 1) {
                        did = true;
                        grid[y][x] = 2;
                        nodes.push({x, y});
                    }
                }
            }
            counter += did;
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }
        return counter;
    }
};
