#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
	// 解法一：并查集
	int numIslands(vector<vector<char>>& grid) {
		m = grid.size();
		n = grid[0].size();
		int sz = m * n;
		fa.resize(sz);
		// makeSet
		for (int i = 0; i < sz; ++i) fa[i] = i;

		// unionSet
		const int dx[4] = {1, -1, 0, 0};
        const int dy[4] = {0, 0, 1 ,-1};
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '0') continue;
				for (int d = 0; d < 4; ++d) {
					int ni = i + dx[d], nj = j + dy[d];
					if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
					if (grid[ni][nj] == '0') continue;
					unionSet(num(i, j), num(ni, nj));
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '0') continue;
				int x = num(i, j);
				if (fa[x] == x)
					++ans;
			}
		}
		return ans;
	}

	int num(int i, int j) {
		return i * n + j;
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
	int m, n;
	vector<int> fa;

    // 解法二：BFS
//    int numIslands(vector<vector<char>>& grid) {
//        this->m = grid.size();
//        this->n = grid[0].size();
//        visited.resize(m, vector<bool>(n, false));
//        int ans = 0;
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                if (grid[i][j] == '1' && !visited[i][j]) {
//                    ++ans;
//                    bfs(grid, i, j);
//                }
//            }
//        }
//        return ans;
//    }
//
//    void bfs(vector<vector<char>>& grid, int i, int j) {
//        const int dx[4] = {1, -1, 0, 0};
//        const int dy[4] = {0, 0, 1 ,-1};
//        queue<pair<int, int>> q;
//        q.push({i, j});
//        visited[i][j] = true;
//        while (!q.empty()) {
//            pair<int, int> p = q.front();
//            q.pop();
//            int x = p.first;
//            int y = p.second;
//
//            for (int d = 0; d < 4; ++d) {
//                int nx = x + dx[d];
//                int ny = y + dy[d];
//                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
//                    continue;
//                if (grid[nx][ny] == '1' && !visited[nx][ny]) {
//                    q.push({nx, ny});
//                    visited[nx][ny] = true;
//                }
//            }
//        }
//    }
//
//private:
//    int m, n;
//    vector<vector<bool>> visited;
};
//leetcode submit region end(Prohibit modification and deletion)
