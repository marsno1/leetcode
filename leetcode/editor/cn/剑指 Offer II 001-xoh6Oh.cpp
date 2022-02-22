#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int divide(int a, int b) {
        bool positive = ((a >= 0) == (b > 0));
        uint num = abs(a);
        uint den = abs(b);
        uint rmn = 0;
        uint mask = 0x80000000;
        uint ans = 0;
        for (int i = 0; i < 32; ++i) {
            rmn <<= 1;
            if (num & mask) rmn |= 1;
            num <<= 1;
            ans <<= 1;
            if (rmn >= den) {
                ans |= 1;
                rmn -= den;
            }
        }

        if (positive) {
            if (ans & mask) ans = 0x7fffffff;
        }
        else ans = ~ans + 1;
        return ans;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
