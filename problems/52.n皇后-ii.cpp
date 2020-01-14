/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
    vector<int> path;
    int count;

public:
    int totalNQueens(int n) {
        count = 0;
        backTracking(n, 0);
        return count;
    }

    void backTracking(int n, int i) {
        if (i >= n) {
            ++count;
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

