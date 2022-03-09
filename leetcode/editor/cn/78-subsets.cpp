#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        recur(nums, 0);
        return ans;
    }

    void recur(vector<int>& nums, int i) {
        if (i == nums.size()) {
            ans.push_back(result);
            return;
        }
        // 不挑选第i个元素
        recur(nums, i + 1);
        // 挑选第i个元素
        result.push_back(nums[i]);
        recur(nums, i + 1);
        // 恢复
        result.pop_back();
    }

private:
    vector<vector<int>> ans;
    vector<int> result;
};
//leetcode submit region end(Prohibit modification and deletion)
