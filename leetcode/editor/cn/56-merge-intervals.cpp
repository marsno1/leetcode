#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 将区间排序
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b){
            return a[0] < b[0] || (a[0] == b[0] ? a[1] < b[1] : false);
        });

        vector<vector<int>> ans;
        // 合并区间
        int start, end = -1;
        for (vector<int>& interval : intervals) {
            if (interval[0] > end) {
                // 保存上一个区间
                if (end != -1)
                    ans.push_back({start, end});
                // 产生新区间
                start = interval[0];
                end = interval[1];
            } else {
                // 与上一个区间重叠，则尝试扩展右边界
                end = max(end, interval[1]);
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
