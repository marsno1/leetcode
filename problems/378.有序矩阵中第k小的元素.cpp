/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第K小的元素
 */

// @lc code=start
class Solution {
public:
    // 优先级队列
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // 大顶堆
        priority_queue<int> q;
        int n = matrix.size();
        int count = 0;
        int i, j;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                q.push(matrix[i][j]);
                if (++count == k) {
                    break;
                }
            }
            if (count == k) {
                break;
            }
        }

        i = k / n;
        j = k % n;
        for (; i < n; ++i) {
            for (; j < n; ++j) {
                if (matrix[i][j] < q.top()) {
                    q.pop();
                    q.push(matrix[i][j]);
                }
            }
            j = 0;
        }
        return q.top();
    }
    
    // 快速选择
    // int kthSmallest(vector<vector<int>>& matrix, int k) {
    //     return quickSelect(matrix, matrix.size(), k - 1);
    // }

    // int quickSelect(vector<vector<int>>& matrix, int n, int k) {
    //     int l = 0, r = n * n - 1;
    //     while (l <= r) {
    //         int p = partition(matrix, n, l, r);
    //         if (k < p) {
    //             r = p - 1;
    //         } else if (k > p) {
    //             l = p + 1;
    //         } else {
    //             return matrix[p/n][p%n];
    //         }
    //     }
    //     return -1;
    // }

    // int partition(vector<vector<int>>& matrix, int n, int l, int r) {
    //     int i = l + 1;
    //     int j = r;
    //     int lrow = l/n, lcol = l%n;
    //     int lv = matrix[lrow][lcol];
    //     int irow, icol, jrow, jcol;
    //     while (i <= j) {
    //         irow = i/n, icol = i%n;
    //         jrow = j/n, jcol = j%n;
    //         int iv = matrix[irow][icol];
    //         int jv = matrix[jrow][jcol];
    //         if (iv > lv && jv < lv) {
    //             swap(matrix[irow][icol], matrix[jrow][jcol]);
    //         } else if (iv <= lv) {
    //             ++i;
    //         } else {
    //             --j;
    //         }
    //     }

    //     // now, j=i-1
    //     jrow = j/n, jcol = j%n;
    //     swap(matrix[lrow][lcol], matrix[jrow][jcol]);
    //     return j;
    // }
};
// @lc code=end

