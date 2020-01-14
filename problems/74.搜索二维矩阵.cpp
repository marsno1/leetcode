/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        int len = m * n;
        int left = 0, right = len - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int r = mid / n;
            int c = mid % n;
            if (target < matrix[r][c]) {
                right = mid - 1;
            } else if (target > matrix[r][c]) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

