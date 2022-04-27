#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
struct State {
	vector<vector<int>> board;
	string hash;
	int cost;
};
// 重载比较函数greater，表示小根堆
bool operator < (const State & a, const State & b) {
	return a.cost > b.cost;
}

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
		State beginState{.board = board, .hash = hashVal(board), .cost = evaluate(board)};
		vector<vector<int>> targetBoard = {{1,2,3}, {4,5,0}};
		targetState = State{.board = targetBoard, .hash = hashVal(targetBoard)};
		return bfs(beginState);
    }

	int bfs(State & beginState) {
		q.push(beginState);
		depth[beginState.hash] = 0;
		while (!q.empty()) {
			State s = q.top();
			q.pop();
			auto zero = findZero(s.board);
			int i = zero.first, j = zero.second;
			if (i == 0) expand(s, i, j, i + 1, j); // 向下
			if (i == 1) expand(s, i, j, i - 1, j); // 向上
			if (j > 0) expand(s, i, j, i, j - 1); // 向左
			if (j < 2) expand(s, i, j , i, j + 1); // 向右
			if (depth.find(targetState.hash) != depth.end())
				return depth[targetState.hash];
		}
		return -1;
	}

	// A*算法估价函数：每个数字当前位置到目标位置的距离之和。
	int evaluate(vector<vector<int>> & board) {
		const static pair<int, int> target[6] = {{}, // 空置
												 {0, 0}, {0, 1}, {0, 2},
												 {1, 0}, {1, 1}};
		int distSum = 0;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 3; ++j) {
				int digit = board[i][j];
				if (digit == 0) continue;
				int ti = target[digit].first;
				int tj = target[digit].second;
				distSum += abs(i - ti) + abs(j - tj);
			}
		}
		return distSum;
	}

	void expand(State & s, int i, int j, int ni, int nj) {
		vector<vector<int>> b = s.board;
		swap(b[i][j], b[ni][nj]);
		string hash = hashVal(b);
		if (depth.find(hash) != depth.end()) return; // 已经访问过该状态了
		// 计算新的步数
		depth[hash] = depth[s.hash] + 1;
		State ns{.board = b,
				 .hash = hash,
				 .cost = depth[hash] + evaluate(b)}; // 当前步数+估计步数
		q.push(ns);
	}

	pair<int, int> findZero(vector<vector<int>>& board) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (board[i][j] == 0) return {i, j};
			}
		}
		return {-1, -1};
	}

	string hashVal(vector<vector<int>>& board) {
		string hash;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 3; ++j) {
				hash += board[i][j] + '0';
			}
		}
		return hash;
	}

private:
	priority_queue<State> q; // 用"当前步数+估计步数"作为排序值
	unordered_map<string, int> depth; // string是State的hash值
	State targetState;
};
//leetcode submit region end(Prohibit modification and deletion)
