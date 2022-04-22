#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool validPalindrome(string s) {
		return check(s, 0, s.length() - 1, 1);
    }

	bool check(string & s, int l, int r, int n) {
		while (l < r) {
			if (s[l] != s[r])
				return n > 0 && (check(s, l + 1, r, n - 1) || check(s, l, r - 1, n - 1));
			++l;
			--r;
		}
		return true;
	}
};
//leetcode submit region end(Prohibit modification and deletion)
