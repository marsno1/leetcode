/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
struct Comp {
    bool operator() (vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }

        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), Comp());
        vector<int> x = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (x[1] >= intervals[i][0]) {
                x[1] = max(x[1], intervals[i][1]);
            } else {
                result.push_back(x);
                x = intervals[i];
            }
        }
        result.push_back(x);
        return result;
    }
};
// @lc code=end

