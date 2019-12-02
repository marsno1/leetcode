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
        int a = 1, b =2;
        for (int i = 3; i <= n; ++i) {
            b = a + b;
            a = b - a;
        }
        return b;
    }
};
// @lc code=end

