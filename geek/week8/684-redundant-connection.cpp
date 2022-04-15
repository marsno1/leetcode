#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
	// 解法二：并查集
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		int n = 1000; // 至多有n个节点
		fa.resize(n + 1);
		// makeSet
		for (int i = 0; i <= n; ++i) fa[i] = i;

		// unionSet
		for (const auto & edge : edges) {
			int x = edge[0], y = edge[1];
			int fx = find(x), fy = find(y);
			// 如果发现两个节点的"集合代表"是同一个，则它们已经在同一棵树上了
			if (fx == fy)
				return edge;
			unionSet(x, y);
		}
		return {};
	}

	int find(int x) {
		if (x == fa[x])
			return x;
		return fa[x] = find(fa[x]);
	}

	void unionSet(int x, int y) {
		x = find(x);
		y = find(y);
		if (x != y)
			fa[x] = y;
	}

private:
	vector<int> fa;

	// 解法二：DFS
//    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//        // 确定最大顶点的编号，用于初始化邻接链表
//        int max_vertex = 0;
//        for (const auto & edge : edges)
//            max_vertex = max(max_vertex, max(edge[0], edge[1]));
//        graph.resize(max_vertex + 1);
//        visited.resize(max_vertex + 1, false);
//
//        // 每加入一条新的边，就判断一次图中是否有环；
//        // 如果有环，则新加入的边就是所求的答案。
//        for (const auto & edge : edges) {
//            // 逐个添加每条边，构造出一个图
//            int x = edge[0];
//            int y = edge[1];
//            graph[x].push_back(y);
//            graph[y].push_back(x);
//
//            // 每次DFS之前清空visited
//            for (int i = 0; i < visited.size(); ++i)
//                visited[i] = false;
//            bool has_cycle = dfs(x, 0);
//            if (has_cycle) {
//                return edge;
//            }
//        }
//        return {};
//    }
//
//    // 代码模板：判断图中是否有环
//    bool dfs(int x, int parent) {
//        visited[x] = true;
//        for (int y : graph[x]) {
//            if (y == parent)
//                continue;
//            if (visited[y])
//                return true;
//            else {
//                bool has_cycle = dfs(y, x);
//                if (has_cycle)
//                    return true;
//            }
//        }
//        return false;
//    }
//
//private:
//    vector<vector<int>> graph; //出边数组
//    vector<bool> visited;
};
//leetcode submit region end(Prohibit modification and deletion)
