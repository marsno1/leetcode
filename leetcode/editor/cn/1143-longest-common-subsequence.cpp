#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // 如果tex1[i]!=text2[j], 则dp[i][j]=max(dp[i-1][j],dp[i][j-1])
        // 如果tex1[i]=text2[j], 则dp[i][j]=dp[i-1][j-1]+1
        // 考虑边界问题，令i,j从1开始递增
        int m = text1.size(), n = text2.size();
        text1 = " " + text1;
        text2 = " " + text2;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i] != text2[j]) {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                } else {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
            }
        }
        return dp[m][n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
