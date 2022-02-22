#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 解法一
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<Rect> s;
        int ans = 0;
        for (int height : heights) {
            int accu_width = 0;
            while (!s.empty() && s.top().height >= height) {
                // 因为栈里保存的是左延宽度，栈顶柱子对应的矩形的实际宽度，是把右边比它高的柱子(即消掉的柱子)的左延宽度累加得到。
                accu_width += s.top().width;
                int area = s.top().height * accu_width;
                ans = max(ans, area);
                s.pop();
            }
            // 由于新柱子消掉了一些它左边比它高(或相等)的柱子，所以它的左延宽度是"消掉柱子的累加宽度"加上它自己的宽度1
            // 对于等高柱子，这里用的也是"被消掉的等高柱子累加后的宽度"，所以符合"左延宽度"的定义
            s.push({height, accu_width + 1});
        }
        return ans;
    }

    struct Rect {
        int height;
        int width; // 左延宽度：表示当前柱子可以向左延伸到的最大宽度
    };

//    // 解法二
//    int largestRectangleArea(vector<int>& heights) {
//        // 技巧1：最右边放一个高度为0的柱子，用于把栈里所有柱子都消掉
//        heights.push_back(0);
//        int n = heights.size();
//        // 维护一个"非单调"递增栈(其中会保存等高的柱子)
//        stack<int> s;
//        // 技巧2：栈底设置-1表示左边界，方便计算右边界与左边界之间的差值，避免判断栈是否为空
//        s.push(-1);
//        int curr;
//        int ans = 0;
//        for (int i = 0; i < n; ++i) {
//            // 1.如果柱子i比栈顶柱子低，则计算栈顶柱子构成的矩形面积。
//            while ((curr = s.top()) != -1 && heights[curr] > heights[i]) {
//                s.pop();
//                int j = s.top();
//                // 以curr为最低柱子，它可以向左、向右扩展出的矩形的宽度区间是(j,i) (这是开区间)；
//                // j与curr之间，curr与i之间的柱子一定比curr高，所以curr是最低柱子。
//                // 如果j是栈底的柱子，那么j之前的柱子都比j高，
//                // 由j扩展出的矩形的边界是[0,i)，所以用-1表示一个虚拟边界方便j对应的矩形的计算。
//                int area = heights[curr] * (i - j - 1);
//                ans = max(ans, area);
//            }
//            // 2.如果柱子i比栈顶柱子高(或相等)，则把i直接入栈。
//            // 对于相等高度的柱子，在上边的while循环"heights[curr] > heights[i]"中被处理：
//            // 柱子i将把多个等高的柱子curr都消掉，而这些等高柱子的最大area将由最左边的那根柱子计算得出，
//            // 所以其他的等高柱子只需要以左边的相邻柱子为左边界即可(虽然这个相邻柱子跟它等高)。
//            s.push(i);
//        }
//
//        return ans;
//    }
};
//leetcode submit region end(Prohibit modification and deletion)
