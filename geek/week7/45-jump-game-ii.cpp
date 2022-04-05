#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 动规
    int jump(vector<int>& nums) {
        int n = nums.size();
        // f[i]表示到达下标i的位置时的最少跳跃次数
        // 由f[i]可推导出下标为[i+1, i+nums[i]]这个区间内所有位置的最少跳跃次数
        vector<int> f(n, 1e9);
        f[0] = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 1; j <= nums[i] && i + j < n; ++j) {
                int target = i + j;
                f[target] = min(f[target], f[i] + 1);
            }
        }
        return f[n - 1];
    }

    // 贪心算法
//    int jump(vector<int>& nums) {
//        int ans = 0;
//        int curr = 0;
//        int right;
//        while (curr < nums.size() - 1) {
//            right = curr + nums[curr]; // 第一跳可到达的最远处
//            if (right >= nums.size() - 1) {
//                ++ans;
//                break;
//            }
//            // [curr+1, right]：在当前位置与最远处之间的位置，都是候选项
//            // 依次检查这些候选项，取第二跳能到达的最远处
//            int right2 = 0; // 记录最优的下一跳的终点
//            int next; // 记录最优的下一跳的起点
//            for (int i = curr + 1; i <= right; ++i) {
//                if (i + nums[i] > right2) {
//                    right2 = i + nums[i];
//                    next = i;
//                }
//            }
//            ++ans;
//            curr = next;
//        }
//        return ans;
//    }
};
//leetcode submit region end(Prohibit modification and deletion)
