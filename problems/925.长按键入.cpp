/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */

// @lc code=start
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int m = name.length();
        int n = typed.length();
        int i = 0;
        int j = 0;
        while (i < m && j < n) {
            if (typed[j] == name[i]) {
                ++i;
                ++j;
            } else if (j > 0 && typed[j] == typed[j - 1]) {
                ++j;
            } else {
                return false;
            }
        }
        return i == m;
    }
};
// @lc code=end

