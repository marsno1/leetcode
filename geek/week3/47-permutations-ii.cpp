#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        chosen.resize(n, false);
        sort(nums.begin(), nums.end());
        recur(nums, 0);
        return ans;
    }

    void recur(vector<int>& nums, int i) {
        if (i == n) {
            ans.push_back(result);
            return;
        }

        int last_value = INT_MAX; // 取一个不存在的值
        for (int k = 0; k < chosen.size(); ++k) {
            // 如果当前的值没有选过（既要判断chosen，也要跳过已经选过的值）
            if (!chosen[k] && nums[k] != last_value) {
                last_value = nums[k]; // 记录下当前这个位置已经选过的值
                result.push_back(nums[k]);
                chosen[k] = true;
                recur(nums, i + 1);
                result.pop_back();
                chosen[k] = false;
            }
        }
    }

private:
    int n;
    vector<bool> chosen;
    vector<int> result;
    vector<vector<int>> ans;
};
//leetcode submit region end(Prohibit modification and deletion)
