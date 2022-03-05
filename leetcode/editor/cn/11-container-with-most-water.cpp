#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int i = 0, j = n - 1;
        while (i < j) {
            int x = j - i;
            // 取较短的线
            int y = height[i] < height[j] ? height[i] : height[j];
            ans = max(ans, x * y);

            if (height[i] < height[j])
                ++i;
            else
                --j;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
