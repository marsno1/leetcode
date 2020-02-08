/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    // 在区间[0,x]中找出y，使y^2<=x, (y-1)^2>x
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long square = (long)mid*mid;
            long square2 = (long)(mid+1)*(mid+1);
            if (square <= x &&  square2> x) {
                return mid;
            } else if (square > x) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return 0;
    }
};
// @lc code=end

