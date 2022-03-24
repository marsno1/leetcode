#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findMin(vector<int>& nums) {
        // 每个元素nums[i]跟最后一个元素比较，如果大于就置为0，如果小于等于就置为1。
        // 那么可以得到一个数组，前一段是0，后一段是1，这是一个升序序列，可以应用二分查找。
        // 则题目所求就是找到第一个1，相当于"查找<=target的最右边的元素"
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] <= nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[right];

    }
};
//leetcode submit region end(Prohibit modification and deletion)
