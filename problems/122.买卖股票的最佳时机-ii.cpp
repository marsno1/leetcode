/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    // 求非单调递增序列
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     if (n == 0) return 0;
    //     int l, h;
    //     int ans = 0;
    //     l = h = prices[0];
    //     for (int i = 1; i < n; ++i) {
    //         if (prices[i] < prices[i - 1]) {
    //             ans += h - l;
    //             l = h = prices[i];
    //         } else {
    //             h = prices[i];
    //         }
    //     }
    //     ans += h - l;
    //     return ans;
    // }

    // 动态规划
    // dp[i][0]: 第i天持有钱的收益, dp[i][1]: 第i天持有股票的收益
    // dp[i][0]=max{dp[i-1][0], dp[i-1][1]+prices[i]}
    // dp[i][1]=max{dp[i-1][1], dp[i-1][0]-prices[i]}
    // 返回dp[n-1][0]
    // 初始: dp[0][0]=0, dp[0][1]=-prices[0]
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int dp[n][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0]=max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][1], dp[i-1][0]-prices[i]);
        }
        return dp[n - 1][0];
    }
};
// @lc code=end

