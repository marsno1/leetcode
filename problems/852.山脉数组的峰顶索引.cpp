/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 0;
        int r = A.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) {
                return mid;
            } else if (A[mid] < A[mid - 1]) {
                // 向左找
                r = mid - 1;
            } else {
                // 向右找
                l = mid + 1;
            }
        }
        return l;
    }
};
// @lc code=end

