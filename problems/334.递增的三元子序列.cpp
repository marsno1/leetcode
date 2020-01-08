/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        vector<int> left_min(n);
        vector<int> right_max(n);
        left_min[0] = INT_MAX;
        right_max[n - 1] = INT_MIN;
        for (int i = 1; i < n; ++i) {
            left_min[i] = min(left_min[i - 1], nums[i - 1]);
        }
        for (int i = n - 2; i >= 0; --i) {
            right_max[i] = max(right_max[i + 1], nums[i + 1]);
        }
        for (int i = 1; i <= n - 2; ++i) {
            if (nums[i] > left_min[i] && nums[i] < right_max[i]) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

