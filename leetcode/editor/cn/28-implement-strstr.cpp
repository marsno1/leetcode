#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
	// RK Hash算法, O(n+m)
    int strStr(string haystack, string needle) {
		int n = haystack.length(), m = needle.length();
		// 把文本串haystack转成b进制数，并按p取模
		int b = 131, p = 1e9 + 7;
		vector<long long> H(n + 1, 0);
		for (int i = 1; i <= n; ++i)
			// a转成1, b转成2, ..., z转成26
			H[i] = (H[i - 1] * b + (haystack[i - 1] - 'a' + 1)) % p;

		// 把模式串needle转成Hneedle数值
		long long Hneedle = 0;
		long long powBM = 1; //表示b的m次方
		for (char ch : needle) {
			Hneedle = (Hneedle * b + (ch - 'a' + 1)) % p;
			powBM = powBM * b % p;
		}

		// 执行匹配
		for (int l = 1; l <= n - m + 1; ++l) {
			int r = l + (m - 1);
			// 判断s[l..r]的hash值是否等于Hneedle
			// 注意：(H[r] - H[l - 1] * powBM) % p 可能是负数，所以+p之后转成0~p之间的数
			if ((((H[r] - H[l - 1] * powBM) % p + p ) % p) == Hneedle
				&& haystack.substr(l - 1, m) == needle) { // 如果遇到hash冲突则做进一步检查
				return l - 1;
			}
		}
		return -1;
    }
	// 第二种实现：
	// 将p设置为2^64，则对p取模就是做64位无符号整数的溢出操作，这叫自然溢出。
	// 这样就可以把代码中所有的%p操作全去掉，同时还要将long long改为unsigned long long。
};
//leetcode submit region end(Prohibit modification and deletion)
