/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower = lowerBound(nums, target, 0, nums.size() - 1);
        int upper = upperBound(nums, target, 0, nums.size() - 1);
        return {lower, upper};
    }

    int lowerBound(vector<int>& nums, int target, int low, int high) {
        if (low > high) {
            return -1;
        }

        int mid = low + (high - low) / 2;
        if (nums[mid] == target && (mid == 0 || nums[mid - 1] < target)) {
            return mid;
        }

        if (target <= nums[mid]) {
            return lowerBound(nums, target, low, mid - 1);
        } else {
            return lowerBound(nums, target, mid + 1, high);
        }
    }

    int upperBound(vector<int>& nums, int target, int low, int high) {
        if (low > high) {
            return -1;
        }

        int mid = low + (high - low) / 2;
        if (nums[mid] == target && (mid == nums.size() - 1 || nums[mid + 1] > target)) {
            return mid;
        }

        if (target < nums[mid]) {
            return upperBound(nums, target, low, mid - 1);
        } else { // target >= nums[id]
            return upperBound(nums, target, mid + 1, high);
        }
    }

};
// @lc code=end

