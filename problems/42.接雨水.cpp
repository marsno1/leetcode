/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    // 1. 双指针法：左右指针分别指向两边最高的柱子
    // 2. 双指针法：维护left_max, right_max
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        if (n < 3) return 0;
        int l = -1, r = n;
        int i = 0, j = n - 1;
        while (i < j) {
            if (height[i] <= height[j]) {
                if (l == -1 || height[i] >= height[l]) {
                    l = i;
                } else {
                    // here, height[l] must be less than or equal to height[r]
                    ans += height[l] - height[i];
                }
                ++i;
            } else { 
                if (r == n || height[j] >= height[r]) {
                    r = j;
                } else {
                    ans += height[r] - height[j];
                }
                --j;
            }
        }
        return ans;
    }

    

    // 递减栈
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0;
        int ans = 0;
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && height[i] > height[s.top()]) {
                int curr = height[s.top()];
                s.pop();
                if (!s.empty()) {
                    ans += (min(height[s.top()], height[i]) - curr) * (i - s.top() - 1);
                } else {
                    break;
                }
            }
            // s is empty or height[i] <= height[s.top()]
            s.push(i);
        }
        return ans;
    }
};
// @lc code=end

