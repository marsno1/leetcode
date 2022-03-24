#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // 求>=target的最左值(向左收缩区间)
        vector<int> ans(2);
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        ans[0] = right;

        // 求<=target的最右值(向右收缩区间)
        left = -1, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (nums[mid] <= target) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        ans[1] = right;

        if (ans[0] > ans[1])
            return {-1, -1};
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
