#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
	// 基于"二维平面"+"曼哈顿距离"的最小生成树
    int minCostConnectPoints(vector<vector<int>>& points) {
		int n  = points.size();
		vector<vector<int>> edges;
		// 1.初始化边的数组
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				// 创建从i点到j点的边
				int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
				edges.push_back({i, j, dist});
			}
		}
		// 2.将边数组按距离从小到大排序
		sort(edges.begin(), edges.end(), [](const vector<int> & a, const vector<int> & b) {
			return a[2] < b[2];
		});

		// 3.初始化并查集
		fa.resize(n);
		for (int i = 0; i < n; ++i) fa[i] = i;

		// 4.运行最小生成树算法(使用并查集)
		int ans = 0;
		for (const auto & edge : edges) {
			int x = edge[0];
			int y = edge[1];
			int z = edge[2];
			x = find(x), y = find(y);
			if (x != y) {
				fa[x] = y;
				ans += z;
			}
		}
		return ans;
    }

private:
	int find(int x) {
		if (fa[x] == x) return x;
		return fa[x] = find(fa[x]);
	}
	vector<int> fa;
};
//leetcode submit region end(Prohibit modification and deletion)
