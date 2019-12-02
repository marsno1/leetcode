/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> result(3);
        int n = nums.size();
        if (n < 3) return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] > 0) {
                break;
            }
            // skip duplicates of  nums[i]
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            result[0] = nums[i];
            int target = 0 - nums[i];
            for (int l = i + 1, r = n - 1; l < r;) {
                if (nums[l] + nums[r] < target) {
                    ++l;
                } else if (nums[l] + nums[r] > target) {
                    --r;
                } else {
                    result[1] = nums[l];
                    result[2] = nums[r];
                    ans.push_back(result);
                    // skip duplicdates of nums[l] and nums[r]
                    for (;l < r && nums[l] == result[1]; ++l);
                    for (;l < r && nums[r] == result[2]; --r);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

