/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    // 滑动窗口
    // int lengthOfLongestSubstring(string s) {  
    //     unordered_set<char> set;
    //     queue<char> que;
    //     unsigned long max_len = 0;
    //     for (int i = 0; i < s.length(); ++i) {
    //         if (set.find(s[i]) != set.end()) {
    //             max_len = max(max_len, que.size());
    //             while (true) {
    //                 char c = que.front();
    //                 que.pop();
    //                 set.erase(c);
    //                 if (c == s[i]) {
    //                     break;
    //                 }
    //             }
    //         }
    //         que.push(s[i]);
    //         set.insert(s[i]);
    //     }
    //     max_len = max(max_len, que.size());
    //     return max_len;
    // }

    // 用指针记录子串的起始位置
    int lengthOfLongestSubstring(string s) {  
        vector<char> dict(256, 0);
        int max_len = 0;
        int start = 0; // start index of substring
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (dict[s[i]] != 0) {
                max_len = max(max_len, i - start);
                while (true) {
                    dict[s[start]] = 0;
                    if (s[start] == s[i]) {
                        ++start;
                        break;
                    }
                    ++start;
                }
            }
            dict[s[i]] = 1;
        }
        max_len = max(max_len, n - start);
        return max_len;
    }
};
// @lc code=end

