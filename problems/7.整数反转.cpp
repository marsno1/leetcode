/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int m;
        long ans = 0;
        while (x != 0) {
            m = x % 10;
            x /= 10;
            ans = ans * 10 + m;
        }
        if (ans < INT_MIN || ans > INT_MAX) return 0;
        return ans;
    }
};
// @lc code=end

