#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = dp[0][1] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] >= 0) {
                dp[i][0] = max(dp[i-1][0] * nums[i], nums[i]);
                dp[i][1] = min(dp[i-1][1] * nums[i], nums[i]);
            } else if (nums[i] < 0) {
                dp[i][0] = max(dp[i-1][1] * nums[i], nums[i]);
                dp[i][1] = min(dp[i-1][0] * nums[i], nums[i]);
            }
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
