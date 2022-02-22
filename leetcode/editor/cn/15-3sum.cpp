#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            // 如果nums[i]的值已经被处理过了，则跳过
            // 这种去重逻辑是"后去重"
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            vector<vector<int>> res = twoSum(nums, i);
            if (!res.empty())
                ans.insert(ans.end(), res.begin(), res.end());
        }
        return ans;
    }

    // 双指针法，找出另外两个数。这两个数的组合可能是多个。
    vector<vector<int>> twoSum(vector<int>& nums, int i) {
        vector<vector<int>> res;
        int target = 0 - nums[i];
        int l = i + 1;
        int r = nums.size() - 1;
        while (l < r) {
            if (nums[l] + nums[r] < target)
                ++l;
            else if (nums[l] + nums[r] > target)
                --r;
            else {
                int lv = nums[l];
                int rv = nums[r];
                res.push_back({nums[i], nums[l], nums[r]});
                // 当找到一组答案后，跳过已经处理过的值
                // 这种去重逻辑是"后去重"
                for(;l < r && nums[l] == lv; ++l);
                for(;l < r && nums[r] == rv; --r);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
