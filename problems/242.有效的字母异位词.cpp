/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> count(26, 0);
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            ++count[s[i] - 'a'];
            --count[t[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) {
                return false;
            }
        }
        return true;   
    }
};
// @lc code=end

