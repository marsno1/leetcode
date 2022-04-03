#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int i = 0;
        for (int child : g) {
            // 找到满足s[i]>=child的最小值
            while (i < s.size() && s[i] < child) ++i;
            if (i < s.size()) {
                ++ans;
                ++i;
            } else
                break;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
