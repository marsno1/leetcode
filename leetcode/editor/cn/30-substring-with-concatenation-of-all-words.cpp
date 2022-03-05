#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // 统计单词集合的计数
        int total_len = 0;
        unordered_map<string, int> words_map;
        for (string & word : words) {
            total_len += word.length();
            words_map[word]++;
        }
        vector<int> ans;
        for (int i = 0; i + total_len <= s.length(); ++i) {
            if (match(s.substr(i, total_len), words_map, words.front().length())) {
                ans.push_back(i);
            }
        }
        return ans;
    }

    // 用计数法判断是否匹配
    bool match(const string & s, unordered_map<string, int> & words_map, int word_len) {
        // 对s切词并计数
        unordered_map<string, int> s_map;
        for (int i = 0; i + word_len <= s.length(); i += word_len) {
            s_map[s.substr(i, word_len)]++;
        }
        // 比对两个map的计数值
        if (s_map.size() != words_map.size())
            return false;
        for (const auto & it : s_map) {
            const auto & word_it = words_map.find(it.first);
            if (word_it == words_map.end() || word_it->second != it.second)
                return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
