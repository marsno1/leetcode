#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isMatch(string s, string p) {
		int n = s.length();
		int m = p.length();
		s = " " + s;
		p = " " + p;

		// 对于f[i][j]来说，有三种决策：
		// 1. if s[i]=p[j], f[i-1][j-1]
		// 2. if p[j]='?', f[i-1][j-1]
		// 3. if p[j]='*', 以下两种情况任意一种满足都可以：
		//   (1) '*'匹配0个字符：f[i][j-1]
		//   (2) '*'匹配1个字符：f[i-1][j]
		vector<vector<bool>> f(n + 1, vector<bool>(m + 1, false));
		f[0][0] = true;
		for (int j = 1; j <= m; ++j) {
			if (p[j] == '*')
				f[0][j] = true;
			else
				break;
		}
		// 状态转移
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (s[i] == p[j]) {
					f[i][j] = f[i-1][j-1];
				} else if (p[j] == '?') {
					f[i][j] = f[i-1][j-1];
				} else if (p[j] == '*') {
					f[i][j] = f[i][j-1] || f[i-1][j];
				}
			}
		}
		return f[n][m];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
