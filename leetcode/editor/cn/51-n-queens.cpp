#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        search(0);

        vector<vector<string>> chessboards; // 棋盘
        for (const auto & res : ans) {
            vector<string> chessboard(n, string(n, '.')); // 用'.'初始化棋盘的每个位置
            for (int row = 0; row < res.size(); ++row) {
                int col = res[row];
                chessboard[row][col] = 'Q';
            }
            chessboards.push_back(chessboard);
        }
        return chessboards;
    }

    void search(int row) {
        if (row == n) {
            ans.push_back(result);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (!used[col] && !usedPlus[row + col] && !usedMinus[row - col]) {
                result.push_back(col);
                used[col] = true;
                usedPlus[row + col] = true;
                usedMinus[row - col] = true;

                search(row + 1);

                result.pop_back();
                used[col] = false;
                usedPlus[row + col] = false;
                usedMinus[row - col] = false;
            }
        }
    }

private:
    int n;
    unordered_map<int, bool> used; // 对应纵向，key是列号
    unordered_map<int, bool> usedPlus; // 对应"/"方向，key是行号加列号
    unordered_map<int, bool> usedMinus; // 对应"\"方向，key是行号减列号
    vector<int> result;
    vector<vector<int>> ans;
};
//leetcode submit region end(Prohibit modification and deletion)
