/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    // 投票法
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int k = 0; // 假设第0个元素是众数
        int count = 1;
        for (int i = 1; i < n; ++i) {
            if (count > 0 && nums[i] == nums[k]) {
                ++count;
            } else {
                if (count == 0) { // 票数为0,重新计票
                    k = i;
                    ++count;
                } else { // nums[i]不等于nums[k],抵消一票
                    --count;
                }
            }
        }
        return nums[k];
    }
};
// @lc code=end

