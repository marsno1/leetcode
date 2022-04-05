#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(int c, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> f(n + 1, vector<vector<int>>(2, vector<int>(c + 1, -1e9)));
        f[0][0][0] = 0;
        prices.insert(prices.begin(), 0);
        for (int i = 1; i <= n; ++i) {
            for (int k = 0; k <= c; ++k) {
                // 不交易或买入(把买入算作一次交易，卖出不算)
                // 如果k=0，那么这个状态表示通过买入0次持有了1股，显然这个状态是不合法的，应该保持负无穷
                if (k > 0)
                    f[i][1][k] = max(f[i - 1][1][k], f[i - 1][0][k - 1] - prices[i]);
                // 不交易或卖出
                f[i][0][k] = max(f[i - 1][0][k], f[i - 1][1][k] + prices[i]);
            }
        }
        int ans = -1e9;
        for (int k = 0; k <= c; ++k) {
            ans = max(ans, f[n][0][k]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
