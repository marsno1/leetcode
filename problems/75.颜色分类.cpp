/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution
{
public:
    // 荷兰国旗问题(把无序数组中的三类元素分段)，使用三指针算法
    void sortColors(vector<int> &nums){
        int i = 0, j = nums.size() - 1;
        int p = 0;
        while (p <= j) {
            if (nums[p] == 0) {
                swap(nums[p], nums[i]);
                ++i;
                ++p;
            } else if (nums[p] == 2) {
                swap(nums[p], nums[j]);
                --j;
            } else if (nums[p] == 1) {
                ++p;
            }
        }
    }

    // 计数排序
    // void sortColors(vector<int>& nums) {
    //     vector<int> counts(3, 0);
    //     for (int i = 0; i < nums.size(); ++i) {
    //         ++counts[nums[i]];
    //     }

    //     int start = 0;
    //     int end = 0;
    //     for (int bucket = 0; bucket <= 2; ++bucket) {
    //         if (bucket > 0)
    //             start += counts[bucket - 1];
    //         end += counts[bucket];
    //         for (int i = start; i < end; ++i) {
    //             nums[i] = bucket;
    //         }
    //     }
    // }

    // 快速排序
    // void sortColors(vector<int>& nums) {
    //     quickSort(nums, 0, nums.size() - 1);
    // }

    // void quickSort(vector<int>& nums, int l, int r) {
    //     if (l >= r) return;
    //     int p = partition(nums, l, r);
    //     quickSort(nums, l, p - 1);
    //     quickSort(nums, p + 1, r);
    // }

    // int partition(vector<int>& nums, int l, int r) {
    //     int i = l + 1;
    //     int j = r;
    //     while (i <= j) {
    //         if (nums[i] > nums[l] && nums[j] < nums[l]) {
    //             swap(nums[i], nums[j]);
    //         } else if (nums[i] <= nums[l]) {
    //             ++i;
    //         } else { // nums[j] >= nums[i]
    //             --j;
    //         }
    //     }
    //     // now, j=i-1 and
    //     // nums[l+1,..,j] <= nums[l], nums[i,..,r] > nums[l]
    //     swap(nums[l], nums[j]);
    //     return j;
    // }
};
// @lc code=end
