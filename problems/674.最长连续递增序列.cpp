/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int max_len = 0;
        int curr_len = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                curr_len = 1;
            } else {
                if (nums[i] > nums[i - 1]) {
                    ++curr_len;
                } else {
                    max_len = max(max_len, curr_len);
                    curr_len = 1;
                }
            }
        }
        max_len = max(max_len, curr_len);
        return max_len;
    }
};
// @lc code=end

