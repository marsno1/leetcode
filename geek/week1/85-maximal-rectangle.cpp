#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> v(rows, vector<int>(cols));

        // 构建每一层柱子的高度
        for (int j = 0; j < cols; ++j) {
            for (int i = 0; i < rows; ++i) {
                if (i == 0) {
                    v[i][j] = matrix[i][j] == '1' ? 1 : 0;
                } else {
                    // 在上一层的高度的基础上累加
                    v[i][j] = matrix[i][j] == '1' ? (v[i - 1][j] + (matrix[i][j] - '0')) : 0;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            // 计算每一层的最大矩形
            int max_area = largestRectangleArea(v[i]);
            ans = max(ans, max_area);
        }
        return ans;
    }

private:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<Rect> s;
        int ans = 0;
        for (int height : heights) {
            int accu_width = 0;
            while (!s.empty() && s.top().height >= height) {
                accu_width += s.top().width;
                int area = s.top().height * accu_width;
                ans = max(ans, area);
                s.pop();
            }
            s.push({height, accu_width + 1});
        }
        return ans;
    }

    struct Rect {
        int height;
        int width;
    };

};
//leetcode submit region end(Prohibit modification and deletion)
