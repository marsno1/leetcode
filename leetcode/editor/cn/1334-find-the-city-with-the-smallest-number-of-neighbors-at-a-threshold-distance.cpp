#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
	// 任意点的最短路径：dijkstra算法
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
		// 初始化带权图的邻接矩阵
		vector<vector<int>> g(n, vector<int>(n, 1e9));
		for (int i = 0; i < n; ++i) g[i][i] = 0;
		for (const auto & edge : edges) {
			int x = edge[0], y = edge[1], z = edge[2];
			g[x][y] = g[y][x] = z;
		}

		// 运行dijkstra算法
		for (int k = 0; k < n; ++k) {
			// 以k点为中继，更新i到j的距离
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		}

		int minNeighbour = 1e9;
		int ans;
		for (int i = 0; i < n; ++i) {
			int neighbour = 0;
			// 统计i点的邻居数量
			for (int j = 0; j < n; ++j) {
				if (i != j && g[i][j] <= distanceThreshold) {
					++neighbour;
				}
			}
			if (minNeighbour > neighbour ||
				minNeighbour == neighbour) { // 当有多个点拥有"最小邻居数"时，取编号最大的点
				minNeighbour = neighbour;
				ans = i;
			}
		}
		return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
