/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
struct Comp1 {
    bool operator() (vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
};

struct Comp2 {
    bool operator() (vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
};

class Solution {
public:
    // 方法一：按区间左边界排序
    // int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    //     if (intervals.size() <= 1)
    //         return 0;

    //     sort(intervals.begin(), intervals.end(), Comp1());

    //     int count = 0; // 记录需要删除的区间的数量
    //     int end = intervals[0][1];
    //     for (int i = 1; i < intervals.size(); ++i) {
    //         if (intervals[i][0] < end) { //有重叠
    //             // 删除“右边界较大的区间”,因为它更可能与后边的区间有重叠
    //             if (intervals[i][1] < end) {
    //                 end = intervals[i][1];
    //             }
    //             ++count;
    //         } else {
    //             end = intervals[i][1];
    //         }
    //     }
    //     return count;
    // }

    // 方法二：按区间右边界排序
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1)
            return 0;

        sort(intervals.begin(), intervals.end(), Comp2());

        int count = 1; // 记录没有重叠的区间的数量
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            // 直接找下一个没有重叠的区间，并计数
            if (intervals[i][0] >= end) {
                end = intervals[i][1];
                count++;
            }
        }
        return intervals.size() - count;
    }
};
// @lc code=end

