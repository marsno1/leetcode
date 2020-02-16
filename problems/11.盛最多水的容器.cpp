/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        // 双指针左右夹逼法
        int l = 0;
        int r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int h = min(height[l], height[r]);
            ans = max(ans, (r - l) * h);
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return ans;
    }
};
// @lc code=end

