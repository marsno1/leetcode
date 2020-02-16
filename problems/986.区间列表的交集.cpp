/*
 * @lc app=leetcode.cn id=986 lang=cpp
 *
 * [986] 区间列表的交集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size();
        int n = B.size();
        int i = 0, j = 0;
        vector<vector<int>> ans;
        while (i < m && j < n) {
            vector<int> &a = A[i];
            vector<int> &b = B[j];
            oneIntersection(a, b, ans);
            if (a[1] < b[1]) {
                ++i;
            } else if (a[1] > b[1]) {
                ++j;
            } else {
                ++i;
                ++j;
            }
        }
        return ans;
    }

    void oneIntersection(vector<int>& a, vector<int>& b, vector<vector<int>>& ans) {
        int l = max(a[0], b[0]);
        int r = min(a[1], b[1]);
        if (l <= r) {
            ans.push_back({l, r});
        }
        // if (a[0] <= b[0] && b[0] <= a[1]) {
        //     ans.push_back({b[0], min(a[1], b[1])});
        // } else if (b[0] <= a[0] && a[0] <= b[1]) {
        //     ans.push_back({a[0], min(a[1], b[1])});
        // }
    }
};
// @lc code=end

