#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 解法一：动态规划
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp(n);
        dp[0] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;

        // 解法二：前缀和+前缀最小值

        // 解法三：贪心
    }
};
//leetcode submit region end(Prohibit modification and deletion)
