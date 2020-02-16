/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int l = 0, r = n - 1;
        while (l < r) {
            char lc = tolower(s[l]);
            char rc = tolower(s[r]);
            if (!shouldCheck(lc)) {
                ++l;
                continue;
            }
            if (!shouldCheck(rc)) {
                --r;
                continue;
            }
            if (lc == rc) {
                ++l;
                --r;
            } else {
                return false;
            }
        }
        return true;
    }
    bool shouldCheck(char c) {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z');
    }
};
// @lc code=end

