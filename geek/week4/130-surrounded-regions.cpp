#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        this->m = board.size();
        this->n = board[0].size();
        visited.resize(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && visited[i][j] == false) {
                    vector<pair<int, int>> path;
                    if(bfs(board, i, j, path) == false) continue;
                    for (const auto & p : path) {
                        board[p.first][p.second] = 'X';
                    }
                }
            }
        }
    }

    // 返回值表示从i,j点出发可到达的区域是否可填充
    bool bfs(vector<vector<char>>& board, int i, int j, vector<pair<int, int>>& path) {
        const int dx[4] = {1, -1, 0, 0};
        const int dy[4] = {0, 0, 1, -1};
        bool isValid = true;
        queue<pair<int, int>> q;
        q.push({i, j});
        path.push_back({i, j});
        visited[i][j] = true;
        while (!q.empty()) {
            const auto & p = q.front();
            int x = p.first, y = p.second;
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    // 搜索到边界了，记录本次搜索结果，但仍要继续搜索其他点，目的是为了把当前可到达区域标记为已访问
                    isValid = false;
                    continue;
                }
                if (board[nx][ny] == 'X' || visited[nx][ny]) continue;
                q.push({nx, ny});
                path.push_back({nx, ny});
                visited[nx][ny] = true;
            }
        }
        return isValid;
    }

private:
    int m, n;
    vector<vector<bool>> visited;
};
//leetcode submit region end(Prohibit modification and deletion)
