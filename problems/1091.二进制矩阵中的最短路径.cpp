/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 */

// @lc code=start
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        int dx[8] = {0, 0, 1, -1, -1, 1, -1, 1};
        int dy[8] = {1, -1, 0, 0, -1, -1, 1, 1};
        queue<pair<int, int>> q;
        grid[0][0] = 1;
        q.push({0, 0});
        while (!q.empty()) {
            pair<int, int> pos = q.front();
            q.pop();
            int x = pos.first;
            int y = pos.second;
            if (x == n - 1 && y == n - 1) {
                return grid[x][y];
            }
            
            for (int d = 0; d < 8; ++d) {
                int next_x = x + dx[d];
                int next_y = y + dy[d];
                if (next_x >= 0 && next_x < n &&
                    next_y >= 0 && next_y < n &&
                    grid[next_x][next_y] == 0) {
                    grid[next_x][next_y] = grid[x][y] + 1;
                    q.push({next_x, next_y});
                }
            }
        }
        return -1;
    }
};
// @lc code=end

