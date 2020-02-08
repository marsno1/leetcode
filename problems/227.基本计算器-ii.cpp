/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        queue<char> q;
        for (auto c : s) {
            if (c != ' ')
                q.push(c);
        }
        q.push('+');
        return calculateQueue(q);
    }

    int calculateQueue(queue<char>& q) {
        stack<int> s;
        int num = 0;
        char sign = '+';
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            if (c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
            } else {
                if (sign == '+') {
                    s.push(num);
                } else if (sign == '-') {
                    s.push(-num);
                } else if (sign == '*') {
                    num = s.top() * num;
                    s.pop();
                    s.push(num);
                } else if (sign == '/') {
                    num = s.top() / num;
                    s.pop();
                    s.push(num);
                }
                sign = c;
                num = 0;
            }
        }

        int sum = 0;
        while (!s.empty()) {
            sum += s.top();
            s.pop();
        }
        return sum;
    }
};
// @lc code=end

