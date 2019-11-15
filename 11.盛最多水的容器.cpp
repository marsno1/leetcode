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
        int max_area = 0;
        for(int i = 0, j = height.size() - 1; i < j;) {
            int area = (j - i) * min(height[i], height[j]);
            max_area = max(max_area, area);
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return max_area;
    }
};
// @lc code=end

