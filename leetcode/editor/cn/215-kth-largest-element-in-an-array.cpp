#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
struct my_greater {
    bool operator() (int l, int r) {
        return l > r;
    }
};
class Solution {
public:
    // 解法一：堆排序
//    int findKthLargest(vector<int>& nums, int k) {
//        // 用小顶堆把更小的元素排除
//        // 小顶堆的输出顺序是升序，所以用greater
//        priority_queue<int, vector<int>, my_greater> q;
//        for (int x : nums) {
//            if (q.size() < k) {
//                q.push(x);
//            } else {
//                if (x > q.top()) {
//                    q.pop();
//                    q.push(x);
//                }
//            }
//        }
//        return q.top();
//    }

    // 解法二：快速选择
    int findKthLargest(vector<int>& nums, int k) {
        // 找第k个最大的元素，等价于找第n-k个最小的元素
        int ans = quickSort(nums, 0, nums.size() - 1, nums.size() - k);
        return nums[ans];
    }

    // 找下标为k的元素，左边都小于等于nums[k]，右边都大于等于nums[k]
    int quickSort(vector<int>& nums, int left, int right, int k) {
        if (left >= right)
            return left;

        int mid = partition(nums, left, right);
        if (k <= mid) {
            return quickSort(nums, left, mid, k);
        } else {
            return quickSort(nums, mid + 1, right, k);
        }
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = left + rand() % (right - left + 1);
        int pivotVal = nums[pivot];
        while (left <= right) {
            // 从左边找到第1个大于等于pivotVal的元素
            while (nums[left] < pivotVal) ++left;
            // 从右边找到第1个小于等于pivotVal的元素
            while (nums[right] > pivotVal) --right;
            if (left == right)
                break;
            if (left < right) {
                swap(nums[left], nums[right]);
                ++left;
                --right;
            }
        }
        return right;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
