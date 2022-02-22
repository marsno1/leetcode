#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            int k = target - nums[i];
            if (m.find(k) != m.end()) {
                return {m[k], i};
            } else {
                m[nums[i]] = i;
            }
        }
        return {};
    }
};
//leetcode submit region end(Prohibit modification and deletion)
