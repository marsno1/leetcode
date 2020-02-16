/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans;
        int min_diff = INT_MAX;
        for (int i = 0; i <= n - 3; ++i) {
            int sum = target - nums[i];
            int l = i + 1, r = n - 1;
            while (l < r) {
                int diff = nums[l] + nums[r] - sum;
                if (diff == 0) {
                    return target;
                }
                if (abs(diff) < min_diff) {
                    ans = nums[i] + nums[l] + nums[r];
                    min_diff = abs(diff);
                }

                if (diff < 0) {
                    ++l;
                } else if (diff > 0) {
                    --r;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

