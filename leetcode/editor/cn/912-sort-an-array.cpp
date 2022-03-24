#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int mid = partition(nums, left, right);
        quickSort(nums, left, mid);
        quickSort(nums, mid + 1, right);
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = left + rand() % (right - left + 1);
        int pivotVal = nums[pivot];
        while (left <= right) {
            while (nums[left] < pivotVal)
                ++left;
            while (nums[right] > pivotVal)
                --right;
            if (left == right) {
                break;
            }
            if (left < right) {
                swap(nums[left], nums[right]);
                ++left;
                --right;
            }
        }
        // 最终right指向的位置与pivotVal所在的位置可能不一样
        // pivotVal可能在right指向位置的前面，也可能在它后面
        // 数组是按"小于等于pivotVal"和"大于等于pivotVal"划分两部分
        // [left, mid]：小于等于pivotVal
        // [mid+1, right]：大于等于pivotVal
        return right;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
