/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    // 回溯
    void solveSudoku(vector<vector<char>>& board) {
       solve(board);
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    continue;
                }
                for (char c = '1'; c <= '9'; ++c) {
                    if (isValid(board, i, j, c)) {
                        board[i][j] = c;
                        if (solve(board)) {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        // 所有格子都已经填满数字
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int k = 0; k < 9; ++k) {
            // 同一行的数字
            if (board[row][k] == c) return false;
            // 同一列的数字
            if (board[k][col] == c) return false;
            // 同一3*3宫内的数字
            int i = (row/3)*3 + k/3;
            int j = (col/3)*3 + k%3;
            if (board[i][j] == c) return false;
        }
        return true;
    }
};
// @lc code=end

