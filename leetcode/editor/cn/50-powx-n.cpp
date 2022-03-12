#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;

        // x^(2^31-1) = x^(2^31)/x
        if (n == (1<<31))
            return 1.0 / (myPow(x, -(n + 1)) * x);

        if (n < 0)
            return 1.0 / myPow(x, -n);

        double p = myPow(x, n / 2);
        double ans = p * p;
        if (n % 2 == 1)
            ans *= x;
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
