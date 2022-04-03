#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 贪心算法
    int jump(vector<int>& nums) {
        int ans = 0;
        int curr = 0;
        int right;
        while (curr < nums.size() - 1) {
            right = curr + nums[curr]; // 第一跳可到达的最远处
            if (right >= nums.size() - 1) {
                ++ans;
                break;
            }
            // [curr+1, right]：在当前位置与最远处之间的位置，都是候选项
            // 依次检查这些候选项，取第二跳能到达的最远处
            int right2 = 0; // 记录最优的下一跳的终点
            int next; // 记录最优的下一跳的起点
            for (int i = curr + 1; i <= right; ++i) {
                if (i + nums[i] > right2) {
                    right2 = i + nums[i];
                    next = i;
                }
            }
            ++ans;
            curr = next;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
