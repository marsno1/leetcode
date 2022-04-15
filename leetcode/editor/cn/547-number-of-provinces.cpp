#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
		int n = isConnected.size();
		fa.resize(n, 0);
		// makeSet
		for (int i = 0; i < n; ++i)
			fa[i] = i;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (isConnected[i][j] == 1)
					unionSet(i, j);
			}
		}

		int ans = 0;
		for (int i = 0; i < n; ++i)
			if (fa[i] == i)
				++ans;
		return ans;
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
};
//leetcode submit region end(Prohibit modification and deletion)
