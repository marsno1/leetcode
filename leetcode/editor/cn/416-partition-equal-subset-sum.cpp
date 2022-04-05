#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 0/1背包问题，动态规划
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum += nums[i];
        // 如果和是奇数，则不能分割
        if (sum % 2 != 0)
            return false;

        int half = sum / 2;
        // f[i][j]表示从第0~i个数里选出来一个子集的元素和为j，是否可行
        vector<vector<bool>> f(n + 1, vector<bool>(half + 1, false));
        nums.insert(nums.begin(), 0);
        f[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= half; ++j) {
                // 两种决策：
                // (1)不选i，那么由f[i - 1][j]转移而来
                // (2)选i，那么由f[i - 1][j-nums[i]]转移而来
                f[i][j] = f[i - 1][j];
                if (j >= nums[i])
                    f[i][j] = f[i][j] | f[i - 1][j-nums[i]];
            }
        }
        return f[n][half];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
