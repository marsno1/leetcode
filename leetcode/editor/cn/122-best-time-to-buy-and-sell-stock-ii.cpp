#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 解法一：贪心算法
//    int maxProfit(vector<int>& prices) {
//        // 收集所有prices[i]-prices[i-1]能盈利的值
//        int ans = 0;
//        for (int i = 1; i < prices.size(); ++i) {
//            if (prices[i] > prices[i - 1]) {
//                ans += prices[i] - prices[i - 1];
//            }
//        }
//        return ans;
//    }

    // 解法二：动态规划
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> f(n + 1, vector<int>(2, -1e9));
        f[0][0] = 0;
        prices.insert(prices.begin(), 0);
        for (int i = 1; i <= n; ++i) {
            f[i][1] = max(f[i-1][1], f[i-1][0] - prices[i]);
            f[i][0] = max(f[i-1][0], f[i-1][1] + prices[i]);
        }
        return f[n][0];
    }

};
//leetcode submit region end(Prohibit modification and deletion)
