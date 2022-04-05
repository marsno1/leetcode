#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 动规：完全背包问题
//    int coinChange(vector<int>& coins, int amount) {
//        int n = coins.size();
//        coins.insert(coins.begin(), 0);
//        vector<vector<int>> f(n + 1, vector<int>(amount + 1, 1e9));
//        f[0][0] = 0;
//        for (int i = 1; i <= n; ++i) {
//            for (int j = 0; j <= amount; ++j) {
//                f[i][j] = f[i - 1][j];
//                if (j >= coins[i])
//                    f[i][j] = min(f[i][j], f[i][j - coins[i]] + 1);
//            }
//        }
//        return f[n][amount] == 1e9 ? -1 : f[n][amount];
//    }

    // 动规：另一种思路
    int coinChange(vector<int>& coins, int amount) {
        vector<int> f(amount + 1, 1e9);
        f[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            // 取所有f[i - coins[j]] + 1中的最小值
            for (int j = 0; j < coins.size(); ++j) {
                if (i - coins[j] >= 0)
                    f[i] = min(f[i], f[i - coins[j]] + 1);
            }
        }
        return f[amount] == 1e9 ? -1 : f[amount];
    }

    // 记忆化搜索
//    int coinChange(vector<int>& coins, int amount) {
//        memo.resize(amount + 1, -1);
//        int ans = search(coins, amount);
//        return ans == INT_MAX ? -1 : ans;
//    }
//    int search(vector<int>& coins, int amount) {
//        if (amount < 0)
//            return -1;
//        if (amount == 0)
//            return 0;
//        // -1表示未搜索过
//        // INT_MAX表示无解
//        if (memo[amount] != -1)
//            return memo[amount];
//
//        memo[amount] = INT_MAX;
//        for (int i = 0; i < coins.size(); ++i) {
//            if (amount < coins[i])
//                continue;
//
//            int ret = search(coins, amount - coins[i]);
//            if (ret >= 0)
//                memo[amount] = min(memo[amount], ret + 1);
//        }
//        return memo[amount];
//    }
//
//private:
//    vector<int> memo;
};
//leetcode submit region end(Prohibit modification and deletion)
