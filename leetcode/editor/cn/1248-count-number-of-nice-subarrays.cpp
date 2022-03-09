#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1);
        sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            // 对每个元素模2，偶数转成0，奇数转成1
            // 然后求前缀和，则"恰好有k个奇数数字的子数组"就是要找到一个子数组的和恰好为k
            sum[i] = sum[i - 1] + nums[i - 1] % 2;
        }

        int ans = 0;
        // 求"和为k的子数组"
        unordered_map<int, int> m;
        for (int i = 0; i <= n; ++i) {
            const auto & it = m.find(sum[i] - k);
            if (it != m.end()) {
                ans += it->second;
            }
            m[sum[i]]++;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
