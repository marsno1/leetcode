/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix_i = 0; // nums[0..i]的前缀和
        int prefix_j; // nums[0..j]的前缀和(j<i)
        int ans = 0;
        unordered_map<int,int> prefix_sum_to_count; // 前缀和与其个数的映射
        prefix_sum_to_count[0] = 1;
        for (int i = 0; i < n; ++i) {
            prefix_i += nums[i];
            prefix_j = prefix_i - k;
            if (prefix_sum_to_count.find(prefix_j) != prefix_sum_to_count.end()) {
                ans += prefix_sum_to_count[prefix_j];
            }
             ++prefix_sum_to_count[prefix_i];
        }
        return ans;
    }
};
// @lc code=end

