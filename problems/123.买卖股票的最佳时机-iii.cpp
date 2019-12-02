/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    // [1,2,3,4,5]
    // 持有现金: k<=(i+1)/2
    // 第0天完成0次 0
    // 第1天完成0次 0
    // 第1天完成1次 1
    // 第2天完成0次 0 //
    // 第2天完成1次 max(1,2)=2
    // 第3天完成0次 0
    // 第3天完成1次 max(2,3)=3
    // 第3天完成2次 -2+4 = 2
    // 第4天完成0次 0
    // 第4天完成1次 max(3,-1+5)=4
    // 第4天完成2次 max(2,-2+5)=3
    // 持有股票:
    // 第0天完成0次 -1
    // 第1天完成0次 -1
    // 第2天完成0次 -1
    // 第2天完成1次 -2
    // 第3天完成0次 max(-1,0-4)=-1 //
    // 第3天完成1次 max(-2,2-5)=-2
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int max_k = 2;
        int k;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(max_k+1, vector<int>(2, 0)));
        dp[0][0][0] = 0;
        dp[0][0][1] = -prices[0];
        for (k = 1; k < max_k; ++k) {
            dp[0][k][1] = INT_MIN;
        }
        for (int i = 1; i < n; ++i) {
            for (k = 0; k <= max_k; ++k) {
                //if (k <= (i+1)/2) {
                    if (k == 0) {
                        dp[i][k][0] = dp[i-1][k][0];
                    } else {
                        dp[i][k][0] = max(dp[i-1][k][0], //不交易
                                    dp[i-1][k-1][1]+prices[i]); //卖出
                    }
               // }
               // if (k <= i/2) {
                    dp[i][k][1] = max(dp[i-1][k][1], //不交易
                                dp[i-1][k][0]-prices[i]); //买入
               // }
            }
        }
        int ans = 0;
        for (k = 0; k <= max_k ; ++k) {
            ans = max(ans, dp[n - 1][k][0]);
        }
        return ans;
    }
};
// @lc code=end

