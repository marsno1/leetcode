#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 搜索算法
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0)
            return {};
        this->digits = digits;
        m['2'] = {'a', 'b', 'c'};
        m['3'] = {'d', 'e', 'f'};
        m['4'] = {'g', 'h', 'i'};
        m['5'] = {'j', 'k', 'l'};
        m['6'] = {'m', 'n', 'o'};
        m['7'] = {'p', 'q', 'r', 's'};
        m['8'] = {'t', 'u', 'v'};
        m['9'] = {'w', 'x', 'y', 'z'};
        search(0);
        return ans;
    }

    void search(int index) {
        if (index == this->digits.length()) {
            ans.push_back(result);
            return;
        }
        for (const char ch : m[digits[index]]) {
            result.push_back(ch);
            search(index + 1);
            result.pop_back();
        }
    }

private:
    string digits;
    unordered_map<char, vector<char>> m; // the mapping of digit to lettters
    string result;
    vector<string> ans;
};
//leetcode submit region end(Prohibit modification and deletion)
