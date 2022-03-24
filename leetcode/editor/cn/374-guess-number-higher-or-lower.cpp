#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int res = guess(mid);
            if (res == 0) {
                return mid;
            }
            if (res < 0) // 猜得过大
                right = mid - 1;
            else // 猜得过小
                left = mid + 1;
        }
        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
