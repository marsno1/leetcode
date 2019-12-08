/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        // f[1] = 1
        // f[2] = 2
        // f[n] = f[n-1] + f[n-2]
        if (n <= 2) {
            return n;
        }
        // int a = 1, b =2;
        // for (int i = 3; i <= n; ++i) {
        //     b = a + b;
        //     a = b - a;
        // }
        // return b;

        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
// @lc code=end

