#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 动规
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            dp[i] = INT_MAX; // 表示无解
            for (int j = 0; j < coins.size(); ++j) {
                if (i - coins[j] < 0) continue; // 忽略值为负的前一个状态
                if (dp[i - coins[j]] == INT_MAX) continue; // 忽略无解的前一个状态
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
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
