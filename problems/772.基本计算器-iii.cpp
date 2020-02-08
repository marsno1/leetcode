class Solution {
public:
    int calculate(string s) {
        queue<char> q;
        for (char c : s) {
            if (c != ' ') {
                q.push(c);
            }
        }
        q.push('+');
        return calculateQueue(q);
    }

    int calculateQueue(queue<char>& q) {
        stack<long> s;
        long num = 0;
        char sign = '+';
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
                
                if (c == ')') {
                    break;
                }
            }
        }

        long sum = 0;
        while (!s.empty()) {
            sum += s.top();
            s.pop();
        }
        return sum;
    }
};