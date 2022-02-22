#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for (int i = 0; i < str.length(); ++i) {
            char ch = str[i];
            if (ch == '(' || ch == '[' || ch == '{') {
                s.push(ch);
                continue;
            }
            if (!s.empty() &&
                ((s.top() == '(' && ch == ')') ||
                 (s.top() == '[' && ch == ']') ||
                 (s.top() == '{' && ch == '}'))) {
                s.pop();
            } else {
                return false;
            }
        }
        if (s.empty())
            return true;
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
