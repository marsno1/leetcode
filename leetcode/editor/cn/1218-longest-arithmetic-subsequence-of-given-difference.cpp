#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        if (n == 1) return 1;

        unordered_map<int, int> m; // mapping of arr[i] value to subsequence's length
        int ans = 1;
        m[arr[0]] = 1;
        for (int i = 1; i < n; ++i) {
            int len = 1; // 以arr[i]结尾的子序列的最大长度，默认为1
            int prev = arr[i] - difference;
            auto it = m.find(prev);
            if (it != m.end()) {
                len = max(len, it->second  + 1);
            }
            m[arr[i]] = len;
            ans = max(ans, len);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
