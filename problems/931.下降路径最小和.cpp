/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        if (n == 1) {
            return A[0][0];
        }
        vector<vector<int>> dp(n, vector<int>(n));
        for (int j = 0; j < n; ++j) {
            dp[0][j] = A[0][j];
        }

        int min_sum = INT_MAX;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = A[i][j] + dp[i-1][j];
                if (j > 0) {
                    dp[i][j] = min(dp[i][j], A[i][j] + dp[i-1][j-1]);
                } 
                if (j < n - 1) {
                    dp[i][j] = min(dp[i][j], A[i][j] + dp[i-1][j+1]);
                }

                if (i == n - 1) {
                    min_sum = min(min_sum, dp[i][j]); 
                }
            }
        }

        return min_sum;
    }
};
// @lc code=end

