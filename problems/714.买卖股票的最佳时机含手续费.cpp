/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    // 动态规划
    // dp[i][0]: 第i天持有现金的收益, dp[i][1]: 第i天持有股票的收益
    // dp[i][0]=max{dp[i-1][0], dp[i-1][1]+prices[i]-fee}
    // dp[i][1]=max{dp[i-1][1], dp[i-1][0]-prices[i]}
    // 初始: dp[0][0]=0, dp[0][1]=-prices[0]
    // 返回dp[n-1][0]
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<vector<int>> dp(n, vector<int>(2,0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]-fee);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]); 
        }
        return dp[n - 1][0];
    }
};
// @lc code=end

