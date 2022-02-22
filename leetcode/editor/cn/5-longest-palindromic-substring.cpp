#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 动态规划
    // 如果s[i+1][j-1]是回文子串，且s[i]=s[j] (其中(i+1) <= (j-1))
    // 那么s[i][j]是回文子串，同时用dp[i][j]表示s[i][j]这个回文子串的长度
    // 如果s[i][j]不是回文子串，则dp[i][j]=0
    // 初始状态：
    // len=1, dp[i][j] = 1
    // len=2, dp[i][j] = 2 if s[i]=s[j]
    string longestPalindrome(string s) {
        int n = s.length();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        int start = 0; // 记录最大回文子串的起始下标
        int max_len = 0; // 记录最大回文子串的长度

        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len == 1 || len == 2) {
                        dp[i][j] = len;
                    } else {
                        dp[i][j] = dp[i+1][j-1] > 0 ? dp[i+1][j-1] +2 : 0;
                    }
                    if (max_len < dp[i][j]) {
                        max_len = dp[i][j];
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, max_len);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
