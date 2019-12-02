/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    // dp[i][j]：word1的长度为i的子串与word2的长度为j的子串的最短编辑距离
    // if word1[i-1]=word2[j-1]: 
    //    dp[i][j] = dp[i-1][j-1], 
    // if word1[i-1]!=word2[j-1]:
    //    dp[i][j] = dp[i-1][j-1]+1, 替换word1[i-1]为word2[j-1]
    //    dp[i][j] = dp[i][j-1]+1, 在word1[0..i-1]后面添加字符word2[j-1]
    //    dp[i][j] = dp[i-1][j]+1, 在word1[0..i-1]后面删除字符word1[i-1]
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                }
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

