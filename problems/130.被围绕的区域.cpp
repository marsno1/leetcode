/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        if (n == 0) return;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && isEdge(i, j, m, n)) {
                    // BFS
                    BFS(board, i, j, m, n);
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    bool isEdge(int i, int j, int m, int n) {
        return i == 0 || i == m - 1 || j == 0 || j == n -1;
    }

    bool isValid(int i, int j ,int m, int n) {
        return i >= 0 && i < m && j >=0 && j< n;
    }

    void BFS(vector<vector<char>>& board, int i, int j, int m, int n) {
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        queue<pair<int, int>> q;
        q.push({i, j});
        board[i][j] = 'A';

        while (!q.empty()) {
            pair<int, int> pos = q.front();
            q.pop();
            int x = pos.first;
            int y = pos.second;
            
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (isValid(nx, ny, m, n) && board[nx][ny] == 'O') {
                    board[nx][ny] = 'A';
                    q.push({nx, ny});
                }
            }
        }
    }
};
// @lc code=end

