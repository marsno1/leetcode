/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    // 中心扩展法
    // string longestPalindrome(string s) {
    //     int n = s.length();
    //     if (n == 0) return s;
    //     int j, k;
    //     int start = 0;
    //     int max_len = 1;
    //     for (int i = 0; i < n; ++i) {
    //         if (i >= 1 && s[i] == s[i - 1]) { // abccba
    //             for (j = i, k = i - 1; 
    //                 j < n && k >= 0 && s[j] == s[k]; 
    //                 ++j, --k);
    //             if (j - k - 1 > max_len) {
    //                 max_len = j - k - 1;
    //                 start = k + 1;
    //             }
    //         }
            
    //         if (i >= 2 && s[i] == s[i - 2]) { // abcxcba
    //             for (j = i, k = i - 2; 
    //                 j < n && k >= 0 && s[j] == s[k]; 
    //                 ++j, --k);
    //             if (j - k - 1 > max_len) {
    //                 max_len = j - k - 1 ;
    //                 start = k + 1;
    //             }
    //         }
    //     }
    //     return s.substr(start, max_len);
    // }

    // 动态规划
    // 如果dp[i][j]是回文子串，且s[i-1]=s[j+1]
    // 那么dp[i-1][j+1]
    // 初始状态：
    // len=1, dp[i][j] = 1
    // len=2, dp[i][j] = 2 if s[i]=s[j]
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return s;
        int dp[n][n];
        int max_len = 0;
        int start;
        memset(dp, 0, sizeof(dp));
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + (len - 1);
                if ((len <= 2 || dp[i+1][j-1] > 0) && s[i] == s[j]) {
                    dp[i][j] = len <= 2 ? len: dp[i+1][j-1] + 2;
                    if (dp[i][j] > max_len) {
                        max_len = dp[i][j];
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, max_len);
    }
};
// @lc code=end

