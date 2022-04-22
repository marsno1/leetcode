#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isMatch(string s, string p) {
		int n = s.length();
		int m = p.length();
		s = " " + s;
		p = " " + p;

		// f[i][j]：表示s[1~i]与p[1~j]能否匹配
		vector<vector<bool>> f(n + 1, vector<bool>(m + 1, false));
		// 初始状态
		f[0][0] = true;
		for (int j = 2; j <= m; j += 2) {
			// 这些都可以和空串匹配：a*, a*b*, a*b*.*
			if (p[j] == '*')
				f[0][j] = true;
			else
				break;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (p[j] >= 'a' && p[j] <= 'z') {
					f[i][j] = f[i - 1][j - 1] && s[i] == p[j];
				} else if (p[j] == '.') {
					f[i][j] = f[i - 1][j - 1];
				} else {
					// 当p[j]是*时，有两种决策：
					// 1."<x>*"或".*"停止匹配
					f[i][j] = f[i][j - 2];
					// 2."<x>*"或".*"匹配一个字符："*"之前可能是字母或"."
					if (p[j - 1] == '.' || s[i] == p[j - 1]) {
						f[i][j] = f[i][j] || f[i - 1][j];
						// 注意这里是f[i - 1][j]：
						// f[i - 1][j]包含子问题f[i - 2][j]
						// f[i - 2][j]包含子问题f[i - 3][j]
						// 由此实现了p[j-1~j]匹配多个字符的功能
					}
				}
			}
		}
		return f[n][m];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
