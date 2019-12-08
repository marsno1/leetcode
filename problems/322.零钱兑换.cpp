/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    // dp[i]=min{dp[i-coins[j]]}+1, 0<=j<n
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                int remain = i - coins[j];
                if (remain >= 0 && dp[remain] != -1) {
                    dp[i] = dp[i] == -1 ? dp[remain] + 1 : min(dp[i], dp[remain] + 1);
                }
            }
        }
        return dp[amount];
    }
};
// @lc code=end

