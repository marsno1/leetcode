#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
// 解法一：遇到乘除号，就计算两个数；遇到加减号就放到列表里。列表里存放的数将都按加法计算。
class Solution {
public:
    int calculate(string s) {
        int num = 0;
        vector<int> nums; // nums里最后存放的数值都将按加法计算
        char prev_sign = '+';
        s += " "; // 为了触发最后一个数值的计算
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if (ch >= '0' && ch <= '9') {
                num = num * 10 + (ch - '0');
            } else {
                // 遇到运算符或表达式的最后一个空格，都触发prev_sign的计算
                if (ch != ' ' || i == s.length() - 1) {
                    switch (prev_sign) {
                        case '+':
                            nums.push_back(num);
                            break;
                        case '-':
                            nums.push_back(-num);
                            break;
                        case '*':
                            nums.back() *= num;
                            break;
                        case '/':
                            nums.back() /= num;
                            break;
                    }
                    num = 0;
                    prev_sign = ch;
                }
            }
        }

        return accumulate(nums.begin(), nums.end(), 0);
    }
};

// 解法二：转成逆波兰表达式
//class Solution {
//public:
//    int calculate(string s) {
//        string num;
//        stack<char> ops;
//        vector<string> tokens; // 后缀表达式
//
//        // 思路：把中缀表达式转成逆波兰表达式(后缀表达式)。借助一个栈保存运算符，其中的运算符的优先级是依次增加的。
//        // 遍历中缀表达式时：
//        // (1)如果当前运算符的优先级高，则当前运算符入栈。如：
//        //    1+2*3 => [1,2,3,*,+] (栈操作顺序：{入+,入*,出*,出+})
//        // (2)如果栈顶运算符的优先级高(或相等)，则栈顶运算符出栈并追加到后缀表达式。如：
//        //    1*2+3 => [1,2,*,3,+] (栈操作顺序：{入*,出*,入+,出+})
//        //    1*2+3*4 => [1,2,*,3,4,*,+] (栈操作顺序：{入*,出*,入+,(加*),出+}，第二个*不入栈)
//
//        // 尾部添加一个空格，以便把最后一个数加入tokens
//        s += " ";
//        for (char ch : s) {
//            if (ch >= '0' && ch <= '9') { // 遇到数字字符
//                num += ch;
//                continue;
//            } else { // 遇到运算符或空格,把数字追加到tokens里
//                if (!num.empty()) { // 如果最后出现两个空格，则num是空串
//                    tokens.push_back(num);
//                    num.clear();
//                }
//            }
//
//            if (ch == ' ')
//                continue;
//
//            char curr_rank = getRank(ch);
//            while (!ops.empty() && getRank(ops.top()) >= curr_rank) {
//                // case2: 把栈顶优先级较高(或相等)的运算符追加到tokens里
//                tokens.push_back(string(1, ops.top()));
//                ops.pop();
//            }
//            // 把当前运算符入栈
//            ops.push(ch);
//        }
//
//        // 最后，把栈里的运算符全追加到tokens里
//        while (!ops.empty()) {
//            tokens.push_back(string(1, ops.top()));
//            ops.pop();
//        }
//
//        return evalRPN(tokens);
//    }
//
//    int getRank(char op) {
//        if (op == '+' || op == '-') return 1;
//        if (op == '*' || op == '/') return 2;
//        return 0;
//    }
//
//    int evalRPN(vector<string>& tokens) {
//        stack<int> nums;
//        for (string & token : tokens) {
//            if (isNumber(token)) {
//                int num = atoi(token.c_str());
//                nums.push(num);
//            } else {
//                int b = nums.top();
//                nums.pop();
//                int a = nums.top();
//                nums.pop();
//                int result = calTwoNumbers(token, a, b);
//                nums.push(result);
//            }
//        }
//        return nums.top();
//    }
//
//    bool isNumber(string& t) {
//        // 因为后缀表达式里每个token要么是运算符，要么是整数(包括正负)，所以这样判断更简单
//        return !(t == "+" || t == "-" || t == "*" || t == "/");
//    }
//
//    int calTwoNumbers(string& op, int a, int b) {
//        if (op == "+") return a + b;
//        if (op == "-") return a - b;
//        if (op == "*") return a * b;
//        if (op == "/") return a / b;
//        return 0;
//    }
//};
//leetcode submit region end(Prohibit modification and deletion)