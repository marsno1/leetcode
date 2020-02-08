/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    // PriorityQueue
    // int findKthLargest(vector<int>& nums, int k) {
    //     priority_queue<int, vector<int>, greater<int>> pq;
    //     for (int i = 0; i < k; ++i) {
    //         pq.push(nums[i]);
    //     }
    //     for (int i = k; i < nums.size(); ++i) {
    //         int min = pq.top();
    //         if (nums[i] > min) {
    //             pq.pop();
    //             pq.push(nums[i]);
    //         }
    //     }
    //     return pq.top();
    // }

    // QuickSelection
    int partition(vector<int>& nums, int lower, int upper) {
        int i = lower + 1;
        int j = upper;
        // 循环中三个条件分支，不管因为哪个分支而退出循环，最后都是j=i-1
        // i之前的元素肯定都是小于等于nums[lower]，所以最后把nums[lower]和nums[j]交换即可
        while (i <= j) {
            if (nums[i] > nums[lower] && nums[j] < nums[lower]) {
            // 左边数比支点大，右边数比支点小，则对调两个数
                swap(nums[i], nums[j]);
                ++i;
                --j;
            } else if (nums[i] <= nums[lower]) {
                ++i;
            } else if (nums[j] >= nums[lower]) {
                --j;
            }
        }
        // j指向的数比lower指向的数小或相等
        swap(nums[lower], nums[j]);
        return j;
    }
    int quickSelect(vector<int>& nums, int lower, int upper, int k) {
        if (lower == upper) {
            return nums[lower];
        }
        int p = partition(nums, lower, upper);
        if (k == p) {
            return nums[p];
        }
        if (k < p) {
            return quickSelect(nums, lower, p - 1, k);
        }
        else {
            return quickSelect(nums, p + 1, upper, k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        // 递归方式
        // return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);

        // 循环方式
        int i = 0, j = nums.size() - 1;
        k = nums.size() - k; // 如果数组按从小到大排序，第k大的元素对应的下标就是n-k
        while (true) {
            int p = partition(nums, i, j);
            if (k < p) {
                j = p - 1;
            } else if (k > p) {
                i = p + 1;
            } else {
                return nums[p];
            }
        }
    }
};
// @lc code=end

