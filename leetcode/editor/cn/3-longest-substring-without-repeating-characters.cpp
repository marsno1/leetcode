#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m; // mapping of charactor to index
        int ans = 0;
        int j = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (m.find(s[i]) != m.end()) {
                // move j to k+1
                int k = m[s[i]];
                for (; j <= k; ++j) {
                    m.erase(s[j]);
                }
            }
            // add s[i]
            m[s[i]] = i;
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
