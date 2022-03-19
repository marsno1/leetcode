#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 广度优先搜索
    int numIslands(vector<vector<char>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        visited.resize(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ++ans;
                    bfs(grid, i, j);
                }
            }
        }
        return ans;
    }

    void bfs(vector<vector<char>>& grid, int i, int j) {
        const int dx[4] = {1, -1, 0, 0};
        const int dy[4] = {0, 0, 1 ,-1};
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                if (grid[nx][ny] == '1' && !visited[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }

private:
    int m, n;
    vector<vector<bool>> visited;
};
//leetcode submit region end(Prohibit modification and deletion)
