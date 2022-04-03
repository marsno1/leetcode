#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // f[i][j]=min(f[i-1][j-1],f[i-1][j])+triangle[i][j]
        int n = triangle.size();
        vector<vector<int>> f(n, vector<int>(n));
        f[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0) {
                    f[i][j] = f[i-1][j] + triangle[i][j];
                } else if (j == i) {
                    f[i][j] = f[i-1][j-1] + triangle[i][j];
                } else {
                    f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j];
                }
            }
        }
        int ans = INT_MAX;
        for (int j = 0; j < n; ++j)
            ans = min(ans, f[n-1][j]);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
