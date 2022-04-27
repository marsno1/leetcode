#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;

		// 因为n = 1<<31 = -2^31， 那么-(n+1)=2^31-1
		//   x^(-2^31)
		// = 1.0/(x^(2^31))
		// = 1.0/(x^(2^31-1) * x) // 把2^31-1替换成-(n+1)
		// = 1.0/(x^(-(n+1)) * x)
		if (n == (1<<31))
			return 1.0 / (myPow(x, -(n + 1)) * x);

		if (n < 0)
			return 1.0 / myPow(x, -n);

#if 0
		// 分治法：
        double p = myPow(x, n / 2);
        double ans = p * p;
        if (n % 2 == 1)
            ans *= x;
#endif
		// 分解二进制法：
		double ans = 1;
		double tmp = x;
		while (n > 0) {
			if ((n & 1) == 1)
				ans = ans * tmp;
			tmp = tmp * tmp;
			n = n >> 1;
		}

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
