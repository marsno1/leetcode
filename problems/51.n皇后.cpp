/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 */

// @lc code=start
class Solution {
    vector<int> path;
    vector<vector<string>> results;
public:
    vector<vector<string>> solveNQueens(int n) {
        backTracking(n, 0);
        return results;
    }

    void backTracking(int n, int i) {
        if (i >= n) {
            vector<string> result;
            for (int p = 0; p < path.size(); ++p) {
                string line;
                for (int k = 0; k < n; ++k) {
                    if (k == path[p]) {
                        line += "Q";
                    } else {
                        line += ".";
                    }
                }
                result.push_back(line);
            }
            results.push_back(result);
            return;
        }

        for (int j = 0; j < n; ++j) {
            if (isValid(i, j)) {
                path.push_back(j);
                backTracking(n, i + 1);
                path.pop_back();
            }
        }
    }

    bool isValid(int r, int c) {
        for (int p = 0; p < path.size(); ++p) {
            if (c == path[p] || abs(c - path[p]) == r - p) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

