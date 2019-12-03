/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    // 动态规划
    // dp[i][k][0]: 第i天完成k笔交易后持有现金的最大收益
    // dp[i][k][1]: 第i天完成k笔交易后持有股票的最大收益
    // dp[i][k][0]=max{
    //      dp[i-1][k][0], //不交易
    //      dp[i-1][k-1][1]+prices[i] //卖出
    // }
    // dp[i][k][1]=max{
    //      dp[i-1][k][1], //不交易
    //      dp[i-1][k][0]-prices[i] //买入
    // }
    // 返回max{dp[n-1][k][0]}
    // 初始: dp[0][0][0]=0, dp[0][0][1]=-prices[0]
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1 || k == 0) return 0;
        int max_k = k;
        long ans = 0;
        if (max_k > n/2) {
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1]) {
                    ans += prices[i] - prices[i - 1];
                }
            }
        } else {
            // 有些状态是不存在的，相当于在搜索空间中，这些状态点是不可达的，应当置为INT_MIN，
            // 以保证在求max()时，忽略掉这些不可达点。
            // 例如：当i=1时，完成1次交易后持有现金是有效的，它的子问题包含“第0天完成1次交易且持有现金”，
            // 但这个子问题是无效的，所以dp[0][1][0]应该置为INT_MIN。
            vector<vector<vector<long>>> dp(n, vector<vector<long>>(max_k+1, vector<long>(2, INT_MIN)));
            dp[0][0][0] = 0; // 第0天交易0次且持有现金时最大收益是0
            dp[0][0][1] = -prices[0]; // 第0天交易0次且持有股票时最大收益是-prices[0]
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
            for (k = 0; k <= max_k; ++k) {
                ans = max(ans, dp[n - 1][k][0]);
            }
    
            // 压缩dp
            // vector<vector<long>> dp(max_k+1, vector<long>(2, INT_MIN));
            // dp[0][0] = 0;
            // dp[0][1] = -prices[0];
            // for (int i = 1; i < n; ++i) {
            //     for (k = 0; k <= max_k; ++k) {
            //         if (k == 0) {
            //             // 任意一天交易0次且持有现金时最大收益都是0
            //             dp[0][0] = 0;
            //             // 任意一天交易0次且持有股票时最大收益是max{-prices[i]}
            //             dp[0][1] = max(dp[0][1], (long)-prices[i]);
            //         } else {
            //             int cash = max(dp[k][0], //不交易
            //                             dp[k-1][1]+prices[i]); //卖出
            //             int stock = max(dp[k][1], //不交易
            //                             dp[k][0]-prices[i]); //买入
            //             dp[k][0] = cash;
            //             dp[k][1] = stock;
            //         }
            //     }
            // }
            // for (k = 0; k <= max_k; ++k) {
            //     ans = max(ans, dp[k][0]);
            // }
        }
        return ans;
    }
};
// @lc code=end

