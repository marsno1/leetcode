/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
    vector<vector<int>> results;
    vector<int> result;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backTracking(candidates, target, 0);
        return results;
    }

    void backTracking(vector<int>& candidates, int target, int curr_index) {
        // 检查合法性
        if (target < 0) {
            return;
        }

        // 检查是否满足条件
        if (target == 0) {
            results.push_back(result);
            return;
        }

        // 遍历所有可能情况：所有节点都可以访问，
        // 但不用访问curr_index之前的元素，因为会重复访问
        for (int i = curr_index; i < candidates.size(); ++i) {
            if (i > curr_index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            result.push_back(candidates[i]);
            backTracking(candidates, target - candidates[i], i+1);
            result.pop_back();
        }
    }
};
// @lc code=end

