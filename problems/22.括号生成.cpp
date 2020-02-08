/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
    
public:
    // 动态规划
    // dp[0] = ""
    // dp[i] = "("+dp[k]+")"+dp[i-k-1], 0<=k<i
    // vector<string> generateParenthesis(int n) {
    //     if (n == 0) return vector<string>();
    //     vector<vector<string>> dp(n + 1);
    //     f(n, dp);
    //     return dp[n];
    // }

    // void f(int n, vector<vector<string>>& dp) {
    //     if (!dp[n].empty()) return;

    //     if (n == 0) {
    //         dp[0].push_back("");
    //         return;
    //     }

    //     for (int k = 0; k < n; ++k) {
    //         f(k, dp);
    //         f(n - k - 1, dp);
    //         vector<string> &a = dp[k];
    //         vector<string> &b = dp[n - k - 1];
    //         for (auto as : a) {
    //             for (auto bs: b) {
    //                 dp[n].push_back("(" + as + ")" + bs);
    //             }
    //         }
    //     }
    // }

    // 搜索
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0) return result;
        f(n, 0, 0, "", result);
        return result;
    }

    void f(int n, int left_used, int right_used, string ans, vector<string>& result) {
        if (left_used == n && right_used == n) {
            result.push_back(ans);
        }

        // 当左括号还未用完时，添加一个左括号
        if (left_used < n) {
            f(n, left_used + 1, right_used, ans + "(", result);
        }
        // 当右括号还未用完且比左括号少时，添加一个右括号
        if (right_used < left_used) {
            f(n, left_used, right_used + 1, ans + ")", result);
        }
    }
};
// @lc code=end

