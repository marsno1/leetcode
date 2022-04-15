#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 区间动规
    int maxCoins(vector<int>& nums) {
        // f[l][r]表示"最后"戳破l~r这些气球时的最多硬币数量
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        f.resize(n + 2, vector<int>(n + 2, -1));
        return recur(nums, 1, n);
    }

    int recur(vector<int>& nums, int l, int r) {
        if (l > r)
            return 0;
        if (f[l][r] != -1)
            return f[l][r];
        for (int p = l; p <= r; ++p) {
            // 当最后戳第p个气球时，计算最多硬币数量
            int left = recur(nums, l, p - 1);
            int right = recur(nums, p + 1, r);
            f[l][r] = max(f[l][r], left + right + nums[l - 1] * nums[p] * nums[r + 1]);
        }
        return f[l][r];
    }

private:
    vector<vector<int>> f;
};
//leetcode submit region end(Prohibit modification and deletion)
