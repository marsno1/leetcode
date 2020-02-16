/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    // 方法一：把中间值跟右边界值比较
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) {
                // 无序点在右边
                l = mid + 1;
            } else {
                // 无序点在左边
                r = mid;
            }
        }
        return nums[l];
    }
};
// @lc code=end

