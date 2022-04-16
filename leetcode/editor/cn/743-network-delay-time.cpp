#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
// 单源最短路
class Solution {
public:
	// dijkstra算法：O(n^2+m)
	struct edge {
		int dst; // 目标点
		int time; // 从源点到达目标点的传递时间
	};
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		// 第1步：建立出边数组
		vector<vector<edge>> edges(n + 1, vector<edge>());
		for (const auto & time : times) {
			int x = time[0], y = time[1], z = time[2];
			edges[x].push_back(edge{.dst = y, .time = z});
		}
		// 第2步：运行行dijkstra算法
		// 分别使用两种实现方法：是否使用优先级队列
		vector<int> dist(n + 1, 1e9);
		dist[k] = 0;
		vector<bool> expand(n + 1, false); // 标记哪些点已经扩展过

		// 第1种方法：不使用堆
//		{
//			for (int round = 1; round <= n; ++round) { // 至多n轮，每轮处理一个点
//				// 找没有扩展过的且dist值最小的点(可以优化成使用小根堆)，该点记为x
//				int minDist = 1e9, x;
//				for (int i = 1; i <= n; ++i) {
//					if (!expand[i] && dist[i] < minDist) {
//						minDist = dist[i];
//						x = i;
//					}
//				}
//				// 从x向外扩展
//				for (const auto &edge: edges[x]) {
//					int y = edge.dst;
//					int z = edge.time;
//					if (dist[y] > dist[x] + z) {
//						dist[y] = dist[x] + z;
//					}
//				}
//				expand[x] = true;
//			}
//		}

		// 第2种方法：使用堆。实现上类似于BFS，但用的是优先级队列，而不是FIFO队列。
		{
			// 使用大根堆，按dist值的相反数排序，堆顶就是最小dist的点
			// first是dist值的相反数，second是点的标号
			priority_queue<pair<int, int>> q;
			q.push({-dist[k], k});
			while (!q.empty()) {
				int x = q.top().second; // 取dist最小的点
				q.pop();
				if (expand[x]) continue; // (因为使用了懒删除)堆里可能保存了已经扩展过的点
				// 从x向外扩展
				for (const auto &edge: edges[x]) {
					int y = edge.dst;
					int z = edge.time;
					if (dist[y] > dist[x] + z) {
						dist[y] = dist[x] + z;
						q.push({-dist[y], y}); // 把新到达的点加入堆
					}
				}
				expand[x] = true;
			}
		}

		// 第3步：找出dist最大的值
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			ans = max(ans, dist[i]);
		return ans == 1e9 ? -1 : ans;
	}

	// bellman-ford算法：O(n*m)
//    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//		vector<int> dist(n + 1, 1e9);
//		dist[k] = 0;
//		for (int round = 1; round <= n - 1; ++round) { // 至多n-1轮就可以求出到达所有点的最短路
//			bool flag = false;
//			for (const auto & t : times) {
//				int x = t[0], y = t[1], z = t[2];
//				if (dist[x] + z < dist[y]) {
//					dist[y] = dist[x] + z;
//					flag = true;
//				}
//			}
//			if (!flag)
//				break;
//		}
//		int ans = 0;
//		for (int i = 1; i <= n; ++i)
//			ans = max(ans, dist[i]);
//		return ans == 1e9 ? -1 : ans;
//	}
};
//leetcode submit region end(Prohibit modification and deletion)
