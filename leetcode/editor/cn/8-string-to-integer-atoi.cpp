#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int myAtoi(string s) {
		int i = 0;
		// 1. 忽略前导空格
		while (i < s.length() && s[i] == ' ') ++i;
		// 2. 处理正负号
		int sign = 1;
		if (i < s.length()) {
			if (s[i] == '+') {
				sign = 1;
				++i;
			} else if (s[i] == '-') {
				sign = -1;
				++i;
			}
		}
		// 3.处理数字
		int ans = 0;
		while (i < s.length()) {
			if (s[i] < '0' || s[i] > '9') break;
			// 处理溢出：变换不等式 ans * 10 + s[i] - '0' > INT_MAX
			if (ans > (INT_MAX - (s[i] - '0')) / 10) {
				if (sign == 1)
					return INT_MAX;
				else
					return INT_MIN;
			}
			ans = ans * 10 + (s[i] - '0'); // 这步必须先算数值，再求加法，否则可能溢出
			++i;
		}
		return sign == 1 ? ans : -ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
