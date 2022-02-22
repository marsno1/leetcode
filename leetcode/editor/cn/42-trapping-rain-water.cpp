#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 解法一：单调栈
    int trap(vector<int>& heights) {
        stack<Rect> s;
        int ans = 0;
        for (int height : heights) {
            int accu_width = 0;
            while(!s.empty() && s.top().height < height) {
                int bottom = s.top().height;
                // 1.累加宽度
                // 计算以栈顶柱子上沿为底的矩形面积时，要把所有被消掉的柱子的左延宽度累加，才能得到矩形实际宽度
                accu_width += s.top().width;

                // 2.弹栈
                s.pop();

                // 如果左边没有柱子，则当前柱子无法容纳水
                if (s.empty())
                    continue;

                // 3.计算答案
                int up = min(s.top().height, height);
                int area = (up - bottom) * accu_width;
                ans += area;
            }
            s.push({height, accu_width + 1});
        }
        return ans;
    }

    // 该矩形表示，以当前柱子的上沿为底构成的矩形，向左扩展到最远。
    struct Rect {
        int height;
        int width; // 左延宽度：该矩形向左能扩展到的最大宽度。
    };

//    // 解法二：前后缀最大值
//    int trap(vector<int>& heights) {
//        int n = heights.size();
//        int ans = 0;
//        vector<int> prefix_max(n), suffix_max(n);
//
//        prefix_max[0] = heights[0];
//        for (int i = 1; i < n; ++i)
//            prefix_max[i] = max(heights[i], prefix_max[i - 1]);
//
//        suffix_max[n - 1] = heights[n - 1];
//        for (int i = n - 2; i >= 0; --i)
//            suffix_max[i] = max(heights[i], suffix_max[i + 1]);
//
//        for (int i = 1; i < n - 1; ++i) {
//            int bottom = heights[i];
//            int up = min(prefix_max[i - 1], suffix_max[i + 1]);
//            if (up > bottom)
//                ans += (up - bottom);
//        }
//        return ans;
//    }

};
//leetcode submit region end(Prohibit modification and deletion)
