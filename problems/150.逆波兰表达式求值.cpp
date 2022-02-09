/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (int i = 0; i < tokens.size(); ++i) {
            if (isNumber(tokens[i])) {
                nums.push(atoi(tokens[i].c_str()));
            } else {
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                if (tokens[i] == "+") {
                    nums.push(a + b);
                } else if (tokens[i] == "-") {
                    nums.push(a - b);
                } else if (tokens[i] == "*") {
                    nums.push(a * b);
                } else if (tokens[i] == "/") {
                    nums.push(a / b);
                }
            }
        }
        return nums.top();
    }

    bool isNumber(string& token) {
        return !(token == "+" || token == "-" || token == "*" || token == "/");
    }
};
// @lc code=end

