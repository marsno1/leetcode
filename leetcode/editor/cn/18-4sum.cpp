#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        this->n = nums.size();
        this->target = target;
        this->sum = 0;
        sort(nums.begin(), nums.end());;
        search(nums, 0);
        return ans;
    }

    void search(vector<int>& nums, int index) {
        if (result.size() == 4 && sum == target) {
            ans.push_back(result);
            return;
        }

        for (int i = index; i < n; ++i) {
            if (n - i < 4 - result.size()) { //剪枝
                return;
            }
            if (i > index && nums[i] == nums[i - 1]) { // 去重
                continue;
            }
            if (i < n - 1 && (sum + nums[i] + long(3 - result.size()) * nums[i + 1]) > target) {
                //剪枝：假设加入当前的元素，以及右边的元素的k倍会超过target(k=还缺的数量)
                return;
            }
            if (i < n - 1 && sum + nums[i] + long(3 - result.size()) * nums[n - 1] < target) {
                //剪枝：假设加入当前的元素，以及最大元素的k倍都湊不够target(k=还缺的数量)
                continue;
            }

            // 放当前元素
            result.push_back(nums[i]);
            sum += nums[i];
            search(nums, i + 1);
            result.pop_back();
            sum -= nums[i];
        }
    }

private:
    int n;
    int target;
    vector<int> result;
    int sum;
    vector<vector<int>> ans;
};
//leetcode submit region end(Prohibit modification and deletion)
