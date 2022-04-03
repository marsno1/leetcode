#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // prices[i]-prices[i-1]
        int ans = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                ans += prices[i] - prices[i - 1];
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
