#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        this->lower = lower;
        this->upper = upper;
        int n = nums.size();
        prefixSum.resize(n + 1);
        prefixSum[0] = 0;
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        return mergeSort(nums, 0, n);
    }

    // 对前缀和数组prefixSum[left...right]排序
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            // 当left<right时，前缀和才对应非空的区间
            // 否则区间就是空，应该返回0
            return 0;
        }
        int mid = left + (right - left) / 2;
        int count1 = mergeSort(nums, left, mid);
        int count2 = mergeSort(nums, mid + 1, right);
        return count1 + count2 + merge(nums, left, mid, right);
    }

    int merge(vector<int>& nums, int left, int mid, int right) {
        // (在原归并排序的基础上添加本步骤)统计本层的满足条件的区间的数量
        int count = 0;
        int i = left, j1 = mid + 1, j2 = mid + 1;
        while (i <= mid) {
            // 找到区间prefixSum[j1..j2)，使其满足：
            // prefixSum[j1] - prefixSum[i] >= lower
            // prefixSum[j2] - prefixSum[i] > upper
            // 即：prefixSum[i]+lower <= prefixSum[j1..j2) <= prefixSum[i]+upper
            // prefixSum[j]-prefixSum[i] : 对应nums[i+1...j]的区间和
            while (j1 <= right && prefixSum[j1] - prefixSum[i] < lower) ++j1;
            while (j2 <= right && prefixSum[j2] - prefixSum[i] <= upper) ++j2;
            count += j2 - j1; // 累加区间数量
            ++i;
        }

        // 合并两个有序数组
        vector<long> tmp(right - left + 1); // 使用long避免溢出
        i = left;
        int j = mid + 1;
        int k = 0;
        while (i <= mid && j <= right) {
            tmp[k++] = prefixSum[i] < prefixSum[j] ? prefixSum[i++] : prefixSum[j++];
        }
        while (i <= mid)
            tmp[k++] = prefixSum[i++];
        while (j <= right)
            tmp[k++] = prefixSum[j++];
        // 复制回原数组
        for (i = left, k = 0; i <= right; ++i, ++k) {
            prefixSum[i] = tmp[k];
        }

        return count;
    }

private:
    int lower, upper;
    vector<long> prefixSum; // 使用long避免溢出
};
//leetcode submit region end(Prohibit modification and deletion)
