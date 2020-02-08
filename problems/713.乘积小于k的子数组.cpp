/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于K的子数组
 */

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int now = 1, count = 0, left = 0;
        for (int right = 0; right < nums.size(); right++) {
            now *= nums[right];
            while (left <= right && now >= k) now /= nums[left++];
            count += right - left + 1;
        }
        return count;
    }
};
// @lc code=end

