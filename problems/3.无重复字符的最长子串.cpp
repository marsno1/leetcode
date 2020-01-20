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

    // 用map保存字符与下标的映射
    // int lengthOfLongestSubstring(string s) {  
    //     unordered_map<char, int> m;
    //     int start = 0;
    //     int max_len = 0;
    //     for (int i = 0; i < s.length(); ++i) {
    //         auto it = m.find(s[i]);
    //         if (it != m.end()) {
    //             int prev_index = it->second;
    //             while (start <= prev_index) {
    //                 m.erase(s[start]);
    //                 ++start;
    //             }
    //         }
    //         m[s[i]] = i;
    //         max_len = max(max_len, i - start + 1);
    //     }
    //     return max_len;
    // }

    // 用数组保存字符与下标的映射
    int lengthOfLongestSubstring(string s) {  
        vector<int> m(256, -1);
        int start = 0;
        int max_len = 0;
        for (int i = 0; i < s.length(); ++i) {
            int prev_index = m[s[i]];
            if (prev_index != -1) {
                while (start <= prev_index) {
                    m[s[start]] = -1;
                    ++start;
                }
            }
            m[s[i]] = i;
            max_len = max(max_len, i - start + 1);
        }
        return max_len;
    }
};
// @lc code=end

