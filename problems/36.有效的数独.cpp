/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.' && !isValid(board, i, j, board[i][j])) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int k = 0; k < 9; ++k) {
            // 同一行的数字
            if (k != col && board[row][k] == c) return false;
            // 同一列的数字
            if (k != row && board[k][col] == c) return false;
            // 同一3*3宫内的数字
            int i = (row/3)*3 + k/3;
            int j = (col/3)*3 + k%3;
            if (i != row && j != col && board[i][j] == c) return false;
        }
        return true;
    }
};
// @lc code=end

