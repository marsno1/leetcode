#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        // 动态规划：两个状态
        int n = nums.size();
        // fLen[i] = max(fLen[j]+1, 1), if nums[i]>nums[j] (0<=j<i)
        vector<int> fLen(n);
        // fCount[i]=sum(fCount[j]), if fLen[j]是最大的
        vector<int> fCount(n);
        // 初始状态
        for (int i = 0; i < n; ++i) {
            fLen[i] = 1;
            fCount[i] = 1;
        }
        // 递推
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (fLen[j] + 1 > fLen[i]) {
                        fLen[i] = fLen[j] + 1;
                        fCount[i] = fCount[j];
                    } else if (fLen[j] + 1 == fLen[i]) {
                        fCount[i] += fCount[j];
                    }
                }
            }
        }
        // 目标值
        int maxLen = 1;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (fLen[i] > maxLen) {
                maxLen = fLen[i];
                count = fCount[i];
            } else if (fLen[i] == maxLen) {
                count += fCount[i];
            }
        }
        return count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
