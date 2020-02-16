/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        
        int max_len = 0;
        int curr_len = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                ++curr_len;
            } else {
                max_len = max(max_len, curr_len);
                curr_len = 1;
            }
        }
        max_len = max(max_len, curr_len);
        return max_len;
    }
};
// @lc code=end

