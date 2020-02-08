/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) {
                return vector<int>{l + 1, r + 1};
            }
            if (sum < target) {
                ++l;
            } else {
                --r;
            }
        }
        return vector<int>();
    }
};
// @lc code=end

