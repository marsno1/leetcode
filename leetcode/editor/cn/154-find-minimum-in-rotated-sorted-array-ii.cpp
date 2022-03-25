#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 题153的升级版，区别是包含重复元素
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < nums[right]) {
                // 排除右边的区间
                right = mid;
            } else if (nums[mid] > nums[right]) {
                // 排除左边的区间
                left = mid + 1;
            } else {
                // mid的位置可能在当前区间的首部或尾部，但mid肯定不等于right
                // 因为二者相等，既然有了nums[mid]的存在，那么可以排除nums[right]
                --right;
            }
        }
        return nums[right];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
