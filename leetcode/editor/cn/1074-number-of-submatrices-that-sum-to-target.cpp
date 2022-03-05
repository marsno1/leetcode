#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            vector<int> sum(n);
            for (int j = i; j < m; ++j) {
                // 当前子矩阵是[i..j][0..n-1]
                // 把二维的子矩阵压缩成一维，转化成一维前缀和问题：
                // sum[k]就是matrix[i..j][k]的和，相当于把[i..j]压缩了
                for (int k = 0; k < n; ++k) {
                    sum[k] += matrix[j][k];
                }
                // 找出一维数组中"和为target的子数组"，这一步相当于在列的方向上枚举。
                ans += numSubarraySumTarget(sum, target);
                // 所以，外层是行的枚举，内层是列的枚举，就能找到所有子矩阵。
            }
        }
        return ans;
    }

    int numSubarraySumTarget(vector<int> & nums, int target) {
        int count = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        int prefix_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum += nums[i];
            const auto & it = m.find(prefix_sum - target);
            if (it != m.end()) {
                // 找到一个或多个子数组满足"和为target"的条件
                count += it->second;
            }
            m[prefix_sum]++;
        }
        return count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
