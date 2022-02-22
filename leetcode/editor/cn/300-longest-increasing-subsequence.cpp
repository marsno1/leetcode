#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // dp[i] = max(dp[j]+1, 1) if nums[i]>nums[j] (0<=j<i)
    // ans = max(dp[i]) (0<=i<n)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        vector<int> dp(n);
        dp[0] = 1;
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
