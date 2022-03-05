#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        prefix_sum.resize(m, vector<int>(n));

        prefix_sum[0][0] = matrix[0][0];
        for (int i = 1; i < m; ++i)
            prefix_sum[i][0] = prefix_sum[i - 1][0] + matrix[i][0];

        for (int j = 1; j < n; ++j)
            prefix_sum[0][j] = prefix_sum[0][j - 1] + matrix[0][j];

        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + matrix[i][j];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int top = row1 == 0 ? 0 : prefix_sum[row1 - 1][col2];
        int left = col1 == 0 ? 0 : prefix_sum[row2][col1 - 1];
        int left_top = (row1 == 0 || col1 == 0) ? 0 : prefix_sum[row1 - 1][col1 - 1];
        return prefix_sum[row2][col2] - (top + left - left_top);
    }

private:
    // 存储二维前缀和
    // 或者使用(m+1)*(n+1)大小的二维数组，第一行和第一列都是0，这样就不用考虑边界问题了
    vector<vector<int>> prefix_sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
//leetcode submit region end(Prohibit modification and deletion)
