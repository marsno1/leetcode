/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int result = 0;
        int n = digits.size();
        int i;
        bool carray = true;
        for (i = n - 1; i >= 0 && carray; --i) {
            ++digits[i];
            digits[i] %= 10;
            carray = digits[i] == 0 ? true : false;
        }
        if (carray) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
// @lc code=end

