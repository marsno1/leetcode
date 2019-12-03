/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int max_k = 2;
        int k;
        vector<vector<vector<long>>> dp(n, vector<vector<long>>(max_k+1, vector<long>(2, INT_MIN)));
        dp[0][0][0] = 0;
        dp[0][0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            for (k = 0; k <= max_k; ++k) {
                if (k == 0) {
                    // 任意一天交易0次且持有现金时最大收益都是0
                    dp[i][0][0] = 0;
                    // 任意一天交易0次且持有股票时最大收益是max{-prices[i]}
                    dp[i][0][1] = max(dp[i-1][0][1], (long)-prices[i]); 
                } else {
                    dp[i][k][0] = max(dp[i-1][k][0], //不交易
                                        dp[i-1][k-1][1]+prices[i]); //卖出
                    dp[i][k][1] = max(dp[i-1][k][1], //不交易
                                        dp[i-1][k][0]-prices[i]); //买入
                }
            }
        }
        long ans = 0;
        for (k = 0; k <= max_k ; ++k) {
            ans = max(ans, dp[n - 1][k][0]);
        }
        return ans;
    }
};
// @lc code=end

