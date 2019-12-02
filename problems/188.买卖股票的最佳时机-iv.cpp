/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    // 动态规划
    // dp[i][k][0]: 第i天完成k笔交易后持有现金的收益
    // dp[i][k][1]: 第i天完成k笔交易后持有股票的收益
    // dp[i][k][0]=max{
    //      dp[i-1][k][0], //不交易
    //      dp[i-1][k-1][1]+prices[i] //卖出
    // }
    // dp[i][k][1]=max{
    //      dp[i-1][k][1], //不交易
    //      dp[i-1][k][0]-prices[i] //买入
    // }
    // 返回max{dp[n-1][k][0],0<=k<=(i+1)/2}
    // 初始: dp[0][0][0]=0, dp[0][0][1]=-prices[0]
    // 
    // 持有现金：k<=(i+1)/2
    // 第0天完成0次 0
    // 第1天完成0次 0
    // 第1天完成1次 max(-3,-3+2=-1)=-1
    // 第2天完成0次 0
    // 第2天完成1次 max(-1,-3+6)=3
    
    // 持有股票：k<=i/2
    // 第0天完成0次 -3
    // 第1天完成0次 -3
    // 第2天完成0次 -3
    // 第2天完成1次 -1-6=-7
    // 第3天完成0次 -3
    // 第3天完成1次 max(-7,3-5)=-2
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
            // dp[i][k>0][0]=
            vector<vector<vector<long>>> dp(n, vector<vector<long>>(max_k+1, vector<long>(2, INT_MIN)));
            dp[0][0][0] = 0; // 任意一天交易0次且持有现金时收益都是0
            dp[0][0][1] = -prices[0]; // 任意一天交易0次且持有股票时收益都是-prices[0]
            for (int i = 1; i < n; ++i) {
                for (k = 0; k <= max_k; ++k) {
                    if (k == 0) {
                        // 任意一天交易0次且持有现金时收益都是0
                        dp[i][0][0] = 0;
                        // 任意一天交易0次且持有股票时收益都是min{prices[i]}
                        dp[i][0][1] = max(dp[i-1][0][1], (long)-prices[i]); 
                       
                    } else {
                        // 第i天最多完成(i+1)/2次交易,当k>(i+1)/2时，取INT_MIN
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
    
            // vector<vector<long>> dp(max_k+1, vector<long>{0, INT_MIN});
            // for (int i = 0; i < n; ++i) {
            //     for (k = 1; k <= max_k; ++k) {                 
            //         dp[k][0] = max(dp[k][0], //不交易
            //                         dp[k][1]+prices[i]); //卖出             
            //         dp[k][1] = max(dp[k][1], //不交易
            //                         dp[k-1][0]-prices[i]); //买入
            //     }
            // }
            // ans = dp[k][0];
        }
        return ans;
    }
};
// @lc code=end

