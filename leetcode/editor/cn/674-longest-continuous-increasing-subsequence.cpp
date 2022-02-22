#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        // dp[i]表示以nums[i]结尾的的连续递增子序列的长度
        vector<int> dp(n);
        dp[0] = 1;
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i-1]) {
                dp[i] = dp[i-1] + 1;
            }
            else {
                dp[i] = 1;
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
