/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    // 定义dp[i][j]: 
    // 如果s[0..i-1]匹配p[0..j-1]则是true; 否则是false
    // 或都说, s的长度为i的子串匹配p的长度为j的子串
    // dp[i][j] = dp[i - 1][j - 1], if p[j-1] != '*' && (s[i-1] == p[j-1] || p[j-1] == '.');
    //   (##a)
    //   (##a) or (##.)
    // dp[i][j] = dp[i][j - 2], if p[j-1] == '*' and the pattern repeats for 0 time;
    //   (##a)
    //   (##a)b*
    // dp[i][j] = dp[i - 1][j-2] && (s[i-1] == p[j - 2] || p[j - 2] == '.'), if p[j-1] == '*' and the pattern repeats for at least 1 time.
    //   (##)a
    //   (##).* or (##)a*
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool> > dp(n + 1, vector<bool>(m + 1, false));
        bool match;
        dp[0][0] = true; // 空串与空串匹配
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                match = false;

                // 以下注释中"x"表示正则表达式中的一个用来精确匹配的字符
                // 1. "x"匹配末尾的字符.要求s, p长度至少为1
                if (i >= 1 && p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.')) {
                    match = match || dp[i - 1][j - 1];
                }

                // 2. "x*"或".*"匹配0个字符.要求p长度至少为2
                if (j >= 2 && p[j - 1] == '*') {
                    match = match || dp[i][j-2];
                }
            
                // 3. "x*"或".*"至少匹配一个字符.要求s长度至少为1, p长度最少为2
                // if (i >= 1 && j >= 2 && p[j - 1] == '*') {
                //     if (p[j - 2] != '.') {
                //         for (int k = i - 1; k >= 0 && s[k] == p[j - 2]; --k) {
                //             match = match || dp[k][j - 2];
                //         }
                //     }
                //     if (p[j - 2] == '.') {
                //         for (int k = i - 1; k >= 0; --k) {
                //             match = match || dp[k][j - 2];
                //         }
                //     }
                // }

                // 3. "x*"或".*"至少匹配一个字符.要求s长度至少为1, p长度最少为2
                // 基于这样的事实：如果s[0..i-2]匹配p[0..j-1], 那么:
                // (1) 当s[i-1]=p[j-2]时, s[0..i-1]也匹配p[0..j-1]. 如 s="aa" p="a*"
                // (2) 当p[j-2]='.'时, s[0..i-1]也匹配p[0..j-1]. 如 s="ab" p=".*"
                if (i >= 1 && j >= 2 && (p[j - 1] == '*' && (s[i - 1] == p[j - 2] || p[j - 2] == '.'))) {
                    match = match || dp[i - 1][j];
                }
                dp[i][j] = match;
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

