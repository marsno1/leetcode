#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // f[i]表示下标i的位置是否可达
        // 由f[i]可推导出下标为[i+1, i+nums[i]]这个区间内所有位置是否可达
        vector<bool> f(n, false);
        f[0] = true;
        for (int i = 0; i < n - 1; ++i) {
            if (!f[i])
                continue;
            for (int j = 1; j <= nums[i] && i + j < n; ++j) {
                f[i + j] = true;
                if (i + j == n - 1)
                    return true;
            }
        }
        return f[n - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
