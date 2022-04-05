#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prefixMin(n);
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                prefixMin[i] = prices[0];
            } else {
                prefixMin[i] = min(prices[i], prefixMin[i - 1]);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, prices[i] - prefixMin[i]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
