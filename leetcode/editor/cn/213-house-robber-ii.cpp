#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 环形DP问题，采用两次动规的解法
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        nums.insert(nums.begin(), 0);
        // f[i][j]表示第i间房在j(0是不偷,1是偷)的决策下的偷窃金额
        vector<vector<int>> f(n + 1, vector<int>(2, -1e9));

        // 第一次动规：第1间房不偷，那么第n间房可偷或不偷
        // 初始状态：第1间房不偷时，金额是0
        // 第1间房偷是非法状态，保持为负无穷
        f[1][0] = 0;
        for (int i = 2; i <= n; ++i) {
            // 第i间房不偷，那么第i-1间房可偷或不偷
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            // 第i间房偷，那么第i-1间房不能偷
            f[i][1] = f[i - 1][0] + nums[i];
        }
        int ans;
        ans = max(f[n][0], f[n][1]);

        // 第二次动规：第1间房偷，那么第n间房不能偷
        f[1][1] = nums[1];
        f[1][0] = 0; // 第1间房也可以不偷，但不是约束条件
        for (int i = 2; i <= n; ++i) {
            // 第i间房不偷，那么第i-1间房可偷或不偷
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            // 第i间房偷，那么第i-1间房不能偷
            f[i][1] = f[i - 1][0] + nums[i];
        }
        ans = max(ans, f[n][0]);

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
