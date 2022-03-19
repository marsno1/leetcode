#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // DFS+记忆化搜索
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        pathLength.resize(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int length = dfs(matrix, i, j);
                ans = max(ans, length);
            }
        }
        return ans;
    }

    // 返回[i][j]这个点的最长递增路径的长度
    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if (pathLength[i][j] > 0) {// 如果已经计算过了
            return pathLength[i][j];
        }

        pathLength[i][j] = 1; // 初始化为1
        static const int dx[4] = {1, -1, 0, 0};
        static const int dy[4] = {0, 0, 1, -1};
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
            if (matrix[ni][nj] <= matrix[i][j]) continue;
            int length = dfs(matrix, ni, nj);
            pathLength[i][j] = max(pathLength[i][j], length + 1);
        }
        return pathLength[i][j];
    }

private:
    int m, n;
    vector<vector<int>> pathLength; // 每个点对应的最长递增路径的长度

    // BFS+拓扑排序
//    int longestIncreasingPath(vector<vector<int>>& matrix) {
//        m = matrix.size();
//        n = matrix[0].size();
//        // 1.构建有向无环图
//        const int dx[4] = {1, -1, 0, 0};
//        const int dy[4] = {0, 0, 1, -1};
//        to.resize(m * n);
//        inDegree.resize(m * n, 0);
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                for (int k = 0; k < 4; ++k) {
//                    int ni = i + dx[k];
//                    int nj = j + dy[k];
//                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
//                    if (matrix[ni][nj] <= matrix[i][j]) continue; // 不是递增的
//                    int a = i * n + j, b = ni * n + nj; // 映射到一维数组的下标
//                    to[a].push_back(b); // 创建一条从a到b的边
//                    inDegree[b]++;
//                }
//            }
//        }
//        bfs();
//        return ans;
//    }
//
//    void bfs() {
//        // 2.执行拓扑排序
//        queue<int> q;
//        for (int i = 0; i < m * n; ++i) {
//            if (inDegree[i] == 0)
//                q.push(i);
//        }
//        vector<int> pathLength(m * n, 1); // 记录到达每个点的路径长度
//        ans = 1;
//        while (!q.empty()) {
//            int a = q.front();
//            q.pop();
//            for (int b : to[a]) {
//                pathLength[b] = max(pathLength[b], pathLength[a] + 1);
//                ans = max(ans, pathLength[b]);
//                --inDegree[b];
//                if (inDegree[b] == 0)
//                    q.push(b);
//            }
//        }
//    }
//
//private:
//    int m, n;
//    vector<vector<int>> to; // 出边数组，大小是m*n
//    vector<int> inDegree; // 入度
//    int ans;
};
//leetcode submit region end(Prohibit modification and deletion)
