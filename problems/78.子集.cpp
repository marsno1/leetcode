/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        search(nums, 0);
        return ans;
    }

    void search(vector<int>& nums, int i) {
        if (i == n) {
            ans.push_back(chosen);
            return;
        }

        // 选第i个数
        chosen.push_back(nums[i]);
        search(nums, i + 1);

        // 不选第i个数
        chosen.pop_back();
        search(nums, i + 1);
    }

    int n;
    vector<int> chosen;
    vector<vector<int>> ans;
};
// @lc code=end

