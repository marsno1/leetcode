/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    // 1. 双指针法：左右指针分别指向两边最高的柱子
    // int trap(vector<int>& height) {
    //     int ans = 0;
    //     int n = height.size();
    //     if (n < 3) return 0;
    //     int l = -1, r = n;
    //     int i = 0, j = n - 1;
    //     while (i < j) {
    //         if (height[i] <= height[j]) {
    //             if (l == -1 || height[i] >= height[l]) {
    //                 l = i;
    //             } else {
    //                 // here, height[l] must be less than or equal to height[r]
    //                 ans += height[l] - height[i];
    //             }
    //             ++i;
    //         } else { 
    //             if (r == n || height[j] >= height[r]) {
    //                 r = j;
    //             } else {
    //                 ans += height[r] - height[j];
    //             }
    //             --j;
    //         }
    //     }
    //     return ans;
    // }

    // 2. 双指针法：维护left_max, right_max
    // int trap(vector<int>& height) {
    //     int n = height.size();
    //     if (n <= 2) return 0;
        
    //     vector<int> left_max(n), right_max(n);
    //     left_max[0] = height[0];
    //     for (int i = 1; i < n; ++i) {
    //         left_max[i] = max(left_max[i - 1], height[i]);
    //     }
    //     right_max[n - 1] = height[n - 1];
    //     for (int i = n - 2; i >= 0; --i) {
    //         right_max[i] = max(right_max[i + 1], height[i]);
    //     }

    //     int ans = 0;
    //     for (int i = 1; i <= n - 2; ++i) {
    //         int curr_volume = min(left_max[i - 1], right_max[i + 1]) - height[i];
    //         ans += curr_volume > 0 ? curr_volume : 0;
    //     }
    //     return ans;
    // }
    

    // 递减栈：以当前柱子curr的顶端为矩形的下边界，以curr左右最高柱子分别为矩形的左右边界
    // 目标：找出curr的两边的最大值
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0;
        int ans = 0;
        stack<int> s;
        s.push(-1);
        for (int i = 0; i < n; ++i) {
            int curr;
            while ((curr = s.top()) != -1 && height[i] > height[curr]) {
                s.pop();
                int j = s.top();
                if (j != -1) {
                    // curr左边有更高的柱子：
                    // 矩形的高度为i,j中的较低柱子与curr的高度差
                    // 矩形的宽度区间为(i,j)
                    int h = min(height[j], height[i]) - height[curr];
                    ans += h * (i - j - 1);
                }
            }
            // s is empty or height[i] <= height[s.top()]
            s.push(i);
        }
        return ans;
    }
};
// @lc code=end

