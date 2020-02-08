/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        queue<char> q;
        for (auto c : s) {
            if (c != ' ') {
                q.push(c);
            }
        }
        // 遇到最后的'+'时，把最后一个数放入栈中
        q.push('+');
        return calculateQueue(q);
    }

    int calculateQueue(queue<char>& q) {
        int num = 0;
        //栈中保存所有以加号相连的数
        stack<int> s;
        char sign = '+'; // num之前的操作符
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            if (c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
            } else if (c == '(') {
                num = calculateQueue(q);
            } else {
                if (sign == '+') {
                    s.push(num);
                } else if (sign == '-') {
                    s.push(-num);
                }
                sign = c;
                num = 0;
                //遇到“)”时，把右括号前面的数放入栈中
                if (c == ')') {
                    break;
                } 
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

