/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    // 动态规划
    // dp[i][0]=max{dp[j][1]}+1, 0<=j<i且nums[i]>nums[j]
    // dp[i][1]=max{dp[j][0]}+1, 0<=j<i且nums[i]<nums[j]
    // dp[0][0]=1, dp[0][1]=1
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        vector<vector<int>> dp(n, vector<int>(2, 1));
        dp[0][0] = 1;
        dp[0][1] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                } else if (nums[i] < nums[j]) {
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                } else {
                    dp[i][0] = max(dp[i][0], dp[j][0]);
                    dp[i][1] = max(dp[i][1], dp[j][1]);
                }
            }
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }

    // 分析：找上升序列的最高点和下降序列的最低点，
    // 它们构成最大的摆动幅度，它们构成的序列就是最长摆动序列
    // int wiggleMaxLength(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n < 2) return n;
    //     int prev_diff = nums[1] - nums[0];
    //     int ans = prev_diff == 0 ? 1 : 2;
    //     for (int i = 2; i < n; ++i) {
    //         int curr_diff = nums[i] - nums[i - 1];
    //         if (curr_diff == 0) {
    //             continue;
    //         }
    //         if (prev_diff == 0 || 
    //             (curr_diff > 0 && prev_diff < 0) ||
    //             (curr_diff < 0 && prev_diff > 0)) {
    //             ++ans;
    //         }
    //         prev_diff = curr_diff;
    //     }
    //     return ans;
    // }
};
// @lc code=end

