#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 动规：完全背包问题
    int numSquares(int n) {
        // 物品是完全平方数，体积是n，价值是1，最优化目标是求最小价值
        // f[i][j]表示在0~i个完全平方数中选出若干个，它们之和达到j时，所选择的数字的最少数量
        int c = 0;
        for (int i = 0; i*i <= n; ++i)
            ++c;

        vector<vector<int>> f(c + 1, vector<int>(n + 1, 1e9));
        f[0][0] = 0;
        for (int i = 1; i <= c; ++i) { // 每个物品体积是i^2
            for (int j = 0; j <= n; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= i * i)
                    f[i][j] = min(f[i][j], f[i][j - i * i] + 1);
            }
        }
        return f[c][n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
