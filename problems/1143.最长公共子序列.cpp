/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    // dp[i][j]表示text1的长度为i的前缀串，与text2的长度为j的前缀串的最长公共子序列
    // dp[i][j]=max{dp[i-1][j-1]+1, // if text1[i - 1]=text2[j - 1]
    // dp[i-1][j],
    // dp[i][j-1]}
    // 初始状态：dp[i][0]=0 0<=i<m, dp[0][j]=0 0<=j<n
    // 返回：dp[m][n]
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

