#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> countBits(int n) {
		vector<int> ans(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			// 利用lowbit运算
			// j = i & (i - 1): 是把i的最后一个1去掉
			// 递推：ans[i]比ans[j]多了一个1
			ans[i] = ans[i & (i - 1)] + 1;
		}
		return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
