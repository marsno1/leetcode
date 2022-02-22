#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while (i >= 0 || j >= 0) {
            if (j < 0 || (i >= 0 && j >=0 && nums1[i] >= nums2[j])) {
                nums1[k] = nums1[i];
                --i;
            } else if (i < 0 || (i >= 0 && j >=0 && nums2[j] >= nums1[i])) {
                nums1[k] = nums2[j];
                --j;
            }
            --k;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
