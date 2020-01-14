/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
    vector<vector<int>> results;
    vector<int> result;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backTracking(k, n, 1);
        return results;
    }

    void backTracking(int k, int n, int curr) {
        // 终止条件：
        // 1. 元素数量够了，n大于0，等于0，小于0都是可能的
        // 2. 元素数量不够，n就小于0或等于0了
        if (k == 0) { // 元素数量够了
            if (n == 0) {
                results.push_back(result);
            }
            // n可能仍然大于0，或已经小于0了
            return;
        } else { // 元素数量不够
            if (n <= 0) {
                return;
            }
        }

        for (int i = curr; i <= 9; ++i) {
            result.push_back(i);
            backTracking(k - 1, n - i, i + 1);
            result.pop_back();
        }
    }
};
// @lc code=end

