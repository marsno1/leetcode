#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 解法：二分答案
    int minDays(vector<int>& bloomDay, int m, int k) {
        // 解空间：左边界是1（等1天），右边界是bloomDay[i]中的最大值（等所有花都开放）
        int maxDay = 0;
        for (int day : bloomDay) {
            maxDay = max(maxDay, day);
        }
        int left = 1, right = maxDay + 1; // 无解时返回该值
        while (left < right) {
            int mid = (left + right) / 2;
            if (validate(bloomDay, m, k, mid)) {
                // 排除"满足判定条件的非最优值"
                right = mid;
            } else {
                // 排除"不满足判定条件值"
                left = mid + 1;
            }
        }
        return right == maxDay + 1 ? -1 : right;
    }

    // 猜答案waitDay是否满足判定条件：
    // 在第waitDay天时，使用相邻的k朵花，制作m束花，能否成功？
    bool validate(vector<int>& bloomDay, int m, int k, int waitDay) {
        int count = 0; // 记录制作了几束花
        int consecutive = 0; // 记录采了连续的几条花
        for (int day: bloomDay) {
            if (day <= waitDay) { // 这朵花盛开了
                ++consecutive;
                if (consecutive == k) { // 凑够了k朵花，记为一束
                    consecutive = 0;
                    ++count;
                }
            } else {
                // 这朵花没开，导致花不再连续
                consecutive = 0;
            }
        }
        return count >= m;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
