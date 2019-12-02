/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子序列
 */

// @lc code=start
class Solution {
public:
    // 定义dp[i][0]为“以nums[i]结尾的子序列的最大乘积”
    // 定义dp[i][1]为“以nums[i]结尾的子序列的最小乘积”
    // 状态转移方程：
    // dp[i][0]=max(nums[i], dp[i-1][0]*nums[i], dp[i-1][1]*nums[i])
    // dp[i][1]=min(nums[i], dp[i-1][0]*nums[i], dp[i-1][1]*nums[i])
    // 所求解为：max(dp[0][0],dp[1][0],...,dp[n-1][0])

    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2));
        int ans = nums[0];
        dp[0][0] = dp[0][1] = nums[0];
        for (int i = 1; i < n; ++i) {
            int p1 = dp[i - 1][0] * nums[i];
            int p2 = dp[i - 1][1] * nums[i];
            if (nums[i] >= 0) {
                dp[i][0] = max(dp[i - 1][0] * nums[i], nums[i]);
                dp[i][1] = min(dp[i - 1][1] * nums[i], nums[i]);
            } else {
                dp[i][0] = max(dp[i - 1][1] * nums[i], nums[i]);
                dp[i][1] = min(dp[i - 1][0] * nums[i], nums[i]);
            }
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
};
// @lc code=end

