#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, Value> m;
        int max_degree = 1;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = m.find(nums[i]);
            if (it == m.end()) {
                m[nums[i]] = Value{.degree = 1, .left = i, .right = i};
            } else {
                it->second.right = i;
                it->second.degree++;
                max_degree = max(max_degree, it->second.degree);
            }
        }

        int ans = nums.size();
        // 检查最大度的所有元素，找到左右边界距离最短的
        for (const auto & it : m) {
            if (it.second.degree == max_degree) {
                int len = it.second.right - it.second.left + 1;
                ans = min(ans, len);
            }
        }
        return ans;
    }

private:
    struct Value {
        int degree;
        int left;
        int right;
    };
};
//leetcode submit region end(Prohibit modification and deletion)
