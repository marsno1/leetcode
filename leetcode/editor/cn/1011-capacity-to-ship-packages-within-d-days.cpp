#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 求解-判定问题，用二分答案法寻找最优解
    int shipWithinDays(vector<int>& weights, int days) {
        // 解空间
        int maxWeight = 0, sumWeight = 0;
        for (int w : weights) {
            maxWeight = max(maxWeight, w);
            sumWeight += w;
        }
        int left = maxWeight, right = sumWeight;
        while (left < right) {
            int mid = (left + right) / 2;
            if (validate(weights, days, mid)) {
                // 排除"满足判定条件但不是最优解"的区间
                right = mid;
            } else {
                // 排除"不满足判定条件"的区间
                left = mid + 1;
            }
        }
        return right;
    }

    bool validate(vector<int>& weights, int days, int load) {
        int sum = 0;
        int count = 1;
        for (int w : weights) {
            if (sum + w <= load) {
                sum += w;
            } else {
                sum = w;
                ++count;
            }
        }
        return count <= days;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
