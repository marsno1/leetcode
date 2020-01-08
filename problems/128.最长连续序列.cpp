/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int curr_len = 0;
        int max_len = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // 找出以nums[i]为起点的连续序列，并计算该序列长度
            if (s.count(nums[i] - 1) == 0) {
                curr_len = 1;
                while (s.count(nums[i] + curr_len) == 1) {
                    ++curr_len;
                }
                max_len = max(max_len, curr_len);
            }
        }
        return max_len;
    }
};
// @lc code=end

