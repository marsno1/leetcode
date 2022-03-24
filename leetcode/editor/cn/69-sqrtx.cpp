#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 整数二分
//    int mySqrt(int x) {
//        unsigned int left = 0, right = x;
//        while (left < right) {
//            unsigned int mid = (left + right + 1) / 2;
//            if (mid <= x / mid) { // 用除法避免mid*mid溢出
//                left = mid;
//            } else {
//                right = mid - 1;
//            }
//        }
//        return right;
//    }

    // 实数二分
    int mySqrt(int x) {
        return (int) myRealSqrt(x);
    }
    double myRealSqrt(double x) {
        double left = 0, right = x;
        while (right - left > 1e-7) { // 精确到一个阈值之内才停止
            double mid = (left + right) / 2;
            if (mid * mid <= x) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return right;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
