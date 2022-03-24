#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 三分查找
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1; // 如果是单调区间，则两端元素可能是峰值
        while (left < right) {
            int lmid = (left + right) / 2;
            int rmid = lmid + 1;
            if (nums[lmid] <= nums[rmid]) {
                // 如果中间段是递增区间，则把左侧区间排除
                left = lmid + 1;
            } else {
                // 如果中间段是递减区间，则把右侧区间排除
                right = rmid - 1;
            }
        }
        return right;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
