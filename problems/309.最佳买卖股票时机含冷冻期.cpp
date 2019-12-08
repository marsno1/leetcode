/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    // 动态规划
    // dp[i][0]: 第i天持有现金的收益, dp[i][1]: 第i天持有股票的收益
    // dp[i][0]=max{dp[i-1][0], dp[i-1][1]+prices[i]}
    // dp[i][1]=max{dp[i-1][1], dp[i-2][0]-prices[i]} if i>=2
    // dp[i][1]=max{dp[i-1][1], -prices[i]} if i<=1
    // 初始: dp[0][0]=0, dp[0][1]=-prices[0]
    // 返回dp[n-1][0]
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<vector<int>> dp(n, vector<int>(2,0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            if (i <= 1) {
                dp[i][1] = max(dp[i-1][1], -prices[i]);
            } else {
                dp[i][1] = max(dp[i-1][1], dp[i-2][0]-prices[i]);
            }
        }
        return dp[n - 1][0];
    }
};
// @lc code=end

