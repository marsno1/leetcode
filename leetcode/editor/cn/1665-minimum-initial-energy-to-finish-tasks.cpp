#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 贪心算法
    int minimumEffort(vector<vector<int>>& tasks) {
        // 按actual-minimum升序排序，从后往前求解
        sort(tasks.begin(), tasks.end(),
             [](vector<int>& a, vector<int>& b){
            return a[0] - a[1] < b[0] - b[1];
        });
        int ans = 0;
        for (int i = tasks.size() - 1; i >= 0; --i) {
            ans = max(ans + tasks[i][0], tasks[i][1]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
