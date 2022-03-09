#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        chosen.resize(nums.size(), false);
        recur(nums, 0);
        return ans;
    }

    // 在第i个位置填上一个元素
    void recur(vector<int>& nums, int i) {
        if (i == nums.size()) {
            ans.push_back(result);
            return;
        }

        // 检查一下哪些元素可以填在位置i上
        for (int k = 0; k < chosen.size(); ++k) {
            if (!chosen[k]) {
                // 选第k个元素
                result.push_back(nums[k]);
                chosen[k] = true;
                // 处理下一个位置
                recur(nums, i + 1);
                // 不选第k个元素
                result.pop_back();
                chosen[k] = false;
            }
        }
    }

private:
    vector<vector<int>> ans;
    vector<bool> chosen;
    vector<int> result;
};
//leetcode submit region end(Prohibit modification and deletion)
