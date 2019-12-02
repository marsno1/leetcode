/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 求众数
 */

// @lc code=start
class Solution {
public:
    // 投票算法
    // int majorityElement(vector<int>& nums) {
    //     int n = nums.size();
    //     int k;
    //     int count = 0;
    //     for (int i = 0; i < n; ++i) {
    //         if (count == 0) {
    //             k = i;
    //             ++count;
    //         } else {
    //             if (nums[i] == nums[k]) {
    //                 ++count;
    //             } else {
    //                 --count;
    //             }
    //         }
    //     }
    //     return nums[k];
    // }
    
    // 分治
    int majorityElement(vector<int>& nums) {
        return f(nums, 0, nums.size());
    }

    int f(vector<int>& nums, int l, int r) {
        if (r - l == 1) {
            return nums[l];
        }
        int lv,rv;
        lv = f(nums, l, l+(r-l)/2);
        rv = f(nums, l+(r-l)/2, r);
        if (lv == rv) {
            return lv;
        } else {
            int lc = 0, rc = 0;
            for (int i = l; i < r; ++i) {
                if (nums[i] == lv) {
                   ++lc;
                }
                if (nums[i] == rv) {
                   ++rc;
                }
            }
            if (lc > rc) {
               return lv;
            } else {
               return rv;
            }
        }
    }
};
// @lc code=end

