#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 解法：二分答案
    int splitArray(vector<int>& nums, int m) {
        // 解空间：左边界是nums[i]中的最大值，右边界是所有nums[i]之和
        int left = 0, right = 0;
        for (int num : nums) {
            left = max(left, num);
            right += num;
        }
        while (left < right) {
            int mid = (left + right) / 2;
            if (validate(nums, m, mid)) {
                // mid是满足条件的值，但可能存在比mid更小的也满足条件的值
                // 排除"满足判定条件的非最优值"
                right = mid;
            } else {
                // 排除"不满足判定条件的值"
                left = mid + 1;
            }
        }
        return right;
    }

    // 判定函数：
    // 把nums这些数放到m个盒子里，盒子大小为size
    // 返回值表示是否能放下
    bool validate(vector<int>& nums, int m, int size) {
        int count = 1; // 按size来存放，需要count个盒子
        int groupSum = 0;
        for (int num : nums) {
            if (groupSum + num <= size) {
                groupSum += num;
            } else {
                // 需要一个新盒子
                groupSum = num;
                ++count;
                if (count > m)
                    return false;
            }
        }
        return count <= m;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
