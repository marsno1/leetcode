/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if(dfs(board, i, j, word, 0)) return true;  
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, int i, int j, string &word, int k) {
        if (board[i][j] != word[k]) return false;
        if (k == word.length() - 1) return true;
        char c = board[i][j];
        board[i][j] = '*';
        if (i - 1 >= 0) { // up
            if (dfs(board, i - 1, j, word, k + 1)) return true;
        }
        if (i + 1 < board.size()) { // down
            if (dfs(board, i + 1, j, word, k + 1)) return true;
        }
        if (j - 1 >= 0) { // left
            if (dfs(board, i, j - 1, word, k + 1)) return true;
        }
        if (j + 1 < board[0].size()) { // right
            if (dfs(board, i, j + 1, word, k + 1)) return true;
        }
        board[i][j] = c;
        return false;
    }
};
// @lc code=end

