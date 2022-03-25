#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // 解空间：左边界是1根；右边界是max(piles[i])，即一次吃掉一堆
        int maxPile = 0;
        for (int pile : piles) {
            maxPile = max(maxPile, pile);
        }
        int left = 1, right = maxPile;
        while (left < right) {
            int mid = (left + right) / 2;
            if (validate(piles, h, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

    // 判断：按k的速度吃香蕉，能不能在h小时内吃完
    bool validate(vector<int>& piles, int h, int k) {
        int count = 0; // 记录吃了多少次(或多少小时，因为每小时只能吃一次)
        for (int pile : piles) {
            count += pile / k;
            count += (pile % k) > 0 ? 1 : 0;
        }
        return count <= h;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
