/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    // 递增栈
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        s.push(-1);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int curr;
            while((curr = s.top()) != -1 && heights[i] < heights[curr]) {
                s.pop();
                int j = s.top();
                // 以curr为最低柱子，它可以向左、向右扩展出的矩形的宽度区间是(j,i)；
                // j与curr之间，curr与i之间的柱子一定比curr高，所以curr是最低柱子。
                // 如果j是栈底的柱子，那么j之前的柱子都比j高，
                // 由j扩展出的矩形的边界是[0,i)，所以用-1表示一个虚拟边界方便j对应的矩形的计算。
                int curr_area = heights[curr] * (i - j - 1);
                ans = max(ans, curr_area);
            }
            s.push(i);
        }

        int curr ;
        while ((curr = s.top()) != -1) {
            s.pop();
            int j = s.top();
            // curr与n之间的柱子肯定都比curr高，因为如果存在比curr低的柱子，那么curr就会被消掉了。
            // 所以curr可以向右扩展到n。
            ans = max(ans, heights[curr] * (n - j - 1));
        }
        return ans; 
    }
};
// @lc code=end

