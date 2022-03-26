#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }

    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right)
            return 0;
        int mid = left + (right - left) / 2;
        int count1 = mergeSort(nums, left, mid);
        int count2 = mergeSort(nums, mid + 1, right);
        return count1 + count2 + merge(nums, left, mid, right);
    }

    int merge(vector<int>& nums, int left, int mid, int right) {
        // (在原归并排序的基础上添加本步骤)统计本层的翻转对的数量
        int i = left, j = mid + 1;
        int count = 0;
        while (i <= mid) {
            // 固定i，找到最大的j
            while (j <= right && nums[i] > 2l * nums[j]) {
                j++;
            }
            count += j - (mid + 1);
            i++;
        }

        // 合并两个有序数组
        vector<int> tmp(right - left + 1);
        i = left, j = mid + 1;
        int k = 0;
        while (i <= mid && j <= right) {
            tmp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
        }
        while (i <= mid)
            tmp[k++] = nums[i++];
        while (j <= right)
            tmp[k++] = nums[j++];
        // 复制回原数组
        for (i = left, k = 0; i <= right; ++i, ++k) {
            nums[i] = tmp[k];
        }

        return count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
