/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    // 对于第i个元素，找到它右边的最大的元素
    int maxProfit(vector<int>& prices) {
        int right_max = INT_MIN;
        int ans = 0;
        for (int i = prices.size() - 1; i >= 0; --i) {
            right_max = max(prices[i], right_max);
            ans = max(ans, right_max - prices[i]);
        }
        return ans;
    }
};
// @lc code=end

