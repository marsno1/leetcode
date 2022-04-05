#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // 动规：完全背包问题
        int n = coins.size();
        coins.insert(coins.begin(), 0);
        vector<vector<int>> f(n + 1, vector<int>(amount + 1, 0));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= amount; ++j) {
                f[i][j] += f[i - 1][j];
                if (j >= coins[i])
                    f[i][j] += f[i][j - coins[i]];
            }
        }
        return f[n][amount];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
