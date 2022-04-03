#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 动态规则：自底向上
    // dp[i] = max(dp[j]+1, 1) if nums[i]>nums[j] (0<=j<i)
    // ans = max(dp[i]) (0<=i<n)
//    int lengthOfLIS(vector<int>& nums) {
//        int n = nums.size();
//        vector<int> dp(n);
//        // 初始状态
//        for (int i = 0; i < n; ++i)
//            dp[i] = 1;
//        // 递推
//        for (int i = 1; i < n; ++i) {
//            for (int j = 0; j < i; ++j) {
//                if (nums[i] > nums[j])
//                    dp[i] = max(dp[i], dp[j] + 1);
//            }
//        }
//        // 目标值
//        int ans = 1;
//        for (int i = 0; i < n; ++i)
//            ans = max(ans, dp[i]);
//        return ans;
//    }

    // 记忆化搜索：自顶向下
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memo.resize(n, 0);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int len = search(nums, i);
            ans = max(ans, len);
        }
        return ans;
    }

    int search(vector<int>& nums, int i) {
        if (memo[i] != 0)
            return memo[i];

        int ret = 1;
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                int len = search(nums, j);
                ret = max(ret, len + 1);
            }
        }
        memo[i] = ret;
        return ret;
    }

private:
    vector<int> memo;
};
//leetcode submit region end(Prohibit modification and deletion)
