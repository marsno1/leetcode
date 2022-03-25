#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 普通二分查找
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int i = mid / n;
            int j = mid % n;
            if (target < matrix[i][j]) {
                right = mid - 1;
            } else if (target > matrix[i][j]) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
