#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 动态规划
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        // f[i][j]表示从s[i..j]子串对应的最长回文子序列的长度
        vector<vector<int>> f(n, vector<int>(n, 0));
        // 初始状态：长度为1的子串就是一个回文串，并且回文串长度是1
        for (int i = 0; i < n; ++i)
            f[i][i] = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j])
                    f[i][j] = f[i + 1][j - 1] + 2;
                else
                    f[i][j] = max(f[i][j - 1], f[i + 1][j]);
            }
        }
        return f[0][n - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
