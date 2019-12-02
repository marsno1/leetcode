/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    // 分治法或二进制法
    // 二进制法：考虑n的二进制表示11111, x^n相当于求 x^(10000)+x^(1000)+x^(100)+x^(10)+x^(1)
    // 即针对n的二进制表示中的1对应的值求pow，再累加
    double myPow(double x, int n) {
        long i = n;
        if (i < 0) i = -i;
        double ans = 1.0;
        // i必须是正数，否则i右移1位就不等于i/2
        for (; i > 0; i >>= 1) {
            if (i & 1) {
                // 把二进制表示中的1对应的pow累加到ans上
                ans *= x;
            }
            // 每当i减少一个二进制位，x就作一次平方
            x *= x;
        }
        return n < 0 ? 1/ans : ans;
    }
};
// @lc code=end

