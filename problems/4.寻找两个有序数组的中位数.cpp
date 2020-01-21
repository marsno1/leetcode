/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int l = m + n;
        if (l % 2 == 1) {
            // 中位数的下标是l/2
            return findKth(nums1, 0, m - 1, nums2, 0, n - 1, l/2 + 1);
        } else {
            // 中位数的下标是l/2-1, l/2
            return (findKth(nums1, 0, m - 1, nums2, 0, n - 1, l/2) + 
                    findKth(nums1, 0, m - 1, nums2, 0, n - 1, l/2 + 1)) / 2.0;
        }
    }

    // 在nums1[l1..h1],nums[l2..h2]中找第k小的元素(k>=1)
    double findKth(vector<int>& nums1, int l1, int h1, vector<int>& nums2, int l2, int h2, int k) {
        int m = h1 - l1 + 1;
        int n = h2 - l2 + 1;
        if (m > n) {
            return findKth(nums2, l2, h2, nums1, l1, h1, k);
        }

        if (m == 0) {
            return nums2[l2 + k - 1];
        }

        if (k == 1) {
            return min(nums1[l1], nums2[l2]);
        }

        int na = min(k/2, m); // 在nums1中取前na个数
        int nb = k - na; // 在nums2中取前nb个数
        int va = nums1[l1 + na - 1]; // nums1前半段的最后一个数
        int vb = nums2[l2 + nb - 1]; // nums2前半段的最后一个数
        if (va == vb) {
            return va;
        }
        if (va < vb) {
            // 将nums1,nums2各分为两段: nums1=AB, nums2=XY
            // 假设A和X的长度之和是k,有以下结论：
            // (1)第k小的数不可能在A中,因为: 假如A中包含第k小的数,由于A的最后一个数比X的第一个数小,那么X的第一个数的位置大于k,即A和X的长度之和会大于k
            // (2)第k小的数不可能在Y中,因为: 假如Y中包含第k小的数,由于X的最后一个数比Y的任意一个数都小,那么X的最后一个数的位置小于k,即A和X的长度之和会小于k
            // 在nums1的后半段和num2的前半段中搜索(把nums1的前半段砍掉)
            return findKth(nums1, l1 + na, h1, nums2, l2, l2 + nb - 1, k - na);
        } else {
            // 在nums1的前半段和nums2的后半段中搜索(把nums2的前半段砍掉)
            return findKth(nums1, l1, l1 + na - 1, nums2, l2 + nb, h2, k - nb);
        }
    }
};
// @lc code=end

