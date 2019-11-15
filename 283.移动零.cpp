/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i, j;
        for (i = 0, j = 0; j < n; ++j) {
            if (nums[j] != 0) {
                nums[i] = nums[j];
                ++i;
            }
        }
        for (; i < n; ++i) {
            nums[i] = 0;
        }
    }
};
// @lc code=end

