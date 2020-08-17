/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            int k = sqrt(i);
            bool is_prime = true;
            for (int j = 2; j <= k; ++j) {
                if (i % j == 0) {
                    is_prime = false;
                    break;
                }
            }
            if (is_prime) {
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

