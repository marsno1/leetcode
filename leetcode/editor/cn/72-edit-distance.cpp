#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        word1 = " " + word1;
        word2 = " " + word2;
        // f[i][j]表示以word1[1]结尾、以word2[j]结尾的两个单词之间转换的最少操作数
        // 最优化目标是求最小值，所以初始值设置为正无穷
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 1e9));
        // 初始状态f[i][0]=i, f[0][j]=j
        for (int i = 0; i <= n; ++i) {
            f[i][0] = i;
        }
        for (int j = 0; j <= m; ++j) {
            f[0][j] = j;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                f[i][j] = min(min(f[i][j - 1] + 1, f[i - 1][j] + 1),
                              f[i - 1][j - 1] + (word1[i] != word2[j]));
            }
        }
        return f[n][m];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
