#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numDistinct(string s, string t) {
		int n = s.length();
		int m = t.length();
		s = " " + s;
		t = " " + t;
		// f[i][j]表示s[1~i]与t[1~j]的子序列出现的个数
		vector<vector<unsigned int>> f(n + 1, vector<unsigned int>(m + 1, 0));
		for (int i = 0; i <= n; ++i)
			f[i][0] = 1;
		// 状态转移
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				// 决策1：不考虑字符s[i]时，使t[1~j]能匹配s[1~j-1]
				f[i][j] = f[i - 1][j];
				// 决策2：考虑字符s[i]时，使t[1~j]能匹配s[1~j]且使s[j]被匹配在内
				if (s[i] == t[j])
					f[i][j] += f[i - 1][j - 1];
			}
		}
		return f[n][m];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
