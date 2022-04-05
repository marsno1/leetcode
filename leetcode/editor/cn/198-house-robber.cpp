#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        // f[i][j]表示第i间房在j(0是不偷,1是偷)的决策下的偷窃金额
        vector<vector<int>> f(n + 1, vector<int>(2, -1e9));
        // 初始状态：第0间房不偷时，金额是0
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            // 第i间房不偷，那么第i-1间房可偷或不偷
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            // 第i间房偷，那么第i-1间房不能偷
            f[i][1] = f[i - 1][0] + nums[i];
        }
        return max(f[n][0], f[n][1]);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
