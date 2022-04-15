#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
	// 单源最短路
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		vector<int> dist(n + 1, 1e9);
		dist[k] = 0;
		for (int i = 1; i <= n - 1; ++i) { // 至多n-1轮就可以求出到达所有点的最短路
			bool flag = false;
			for (const auto & t : times) {
				int x = t[0], y = t[1], z = t[2];
				if (dist[x] + z < dist[y]) {
					dist[y] = dist[x] + z;
					flag = true;
				}
			}
			if (!flag)
				break;
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			ans = max(ans, dist[i]);
		return ans == 1e9 ? -1 : ans;
	}

private:

};
//leetcode submit region end(Prohibit modification and deletion)
