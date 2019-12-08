/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
class Solution {
public:
    // 动态规划
    // 状态定义：定义dp[i]为以nums[i]结尾的nums[0..i]的最长上升子序列长度。
    // 状态转移方程：dp[i] = max(dp[j])+1，其中0<=j<i且nums[i]>nums[j]
    // 返回：max(dp[i])
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n == 0) return 0;
    //     vector<int> dp(n);
    //     dp[0] = 1;
    //     int ans = 1;
    //     for (int i = 1; i < n; ++i) {
    //         dp[i] = 1;
    //         for (int j = 0; j < i; ++j) {
    //             if (nums[i] > nums[j]) {
    //                 dp[i] = max(dp[i], dp[j] + 1);
    //             }
    //         }
    //         ans = max(ans, dp[i]);
    //     }
    //     return ans;
    // }

    // 二分查找
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for (int i = 0; i < nums.size(); ++i) {
            auto lower = lower_bound(lis.begin(), lis.end(), nums[i]);
            if (lower == lis.end()) {
                lis.push_back(nums[i]);
            } else {
                *lower = nums[i];
            }
        }
        return lis.size();
    }
};
// @lc code=end

