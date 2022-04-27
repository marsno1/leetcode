#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		// 实现二的初始化：
		for (int i = 0; i < 9; ++i) {
			for (int d = 1; d <= 9; ++d) {
				row[i][d] = true;
				col[i][d] = true;
				box[i][d] = true;
			}
		}

		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				char ch = board[i][j];
				if (ch == '.') continue;
				int d = ch - '0';
				row[i][d] = false;
				col[j][d] = false;
				box[boxIndex(i, j)][d] = false;
			}
		}
		// 搜索
		dfs(board);
	}

	// 实现一：找一个空格子，填之前检查一下是否可以填某个数字
//	bool dfs(vector<vector<char>>& board) {
//		pair<int, int> firstEmpty = findFirstEmpty(board);
//		int i = firstEmpty.first;
//		int j = firstEmpty.second;
//		// 所有格子都已经填满数字
//		if (i == -1) return true;
//
//		// 在空格子里尝试填一个数字
//		for (char c = '1'; c <= '9'; ++c) {
//			// 剪枝：检查当前格子是否可以填某个数字
//			if (isValid(board, i, j, c)) {
//				board[i][j] = c;
//				if (dfs(board)) return true;
//				board[i][j] = '.';
//			}
//		}
//		return false;
//	}
//	// 找第一个空格子
//	pair<int, int> findFirstEmpty(vector<vector<char>>& board) {
//		for (int i = 0; i < 9; ++i) {
//			for (int j = 0; j < 9; ++j) {
//				if (board[i][j] != '.') continue;
//				return {i, j};
//			}
//		}
//		return {-1, -1};
//	}
//	bool isValid(vector<vector<char>>& board, int row, int col, char c) {
//		for (int k = 0; k < 9; ++k) {
//			// 同一行的数字
//			if (board[row][k] == c) return false;
//			// 同一列的数字
//			if (board[k][col] == c) return false;
//			// 同一3*3盒子内的数字
//			int i = (row/3)*3 + k/3;
//			int j = (col/3)*3 + k%3;
//			if (board[i][j] == c) return false;
//		}
//		return true;
//	}

	// 实现二(在实现一的基础上优化，加入剪枝)：找一个可能性最小的格子，只尝试所有可能的数字
	bool dfs(vector<vector<char>>& board) {
		// 找可能性最小的格子
		auto minPro = findMinProbability(board);
		auto pos = minPro.first;
		// 没有找到格子
		if (pos.first == -1) return true;

		auto availableDigits = minPro.second;
		int i = pos.first;
		int j = pos.second;
		// 在空格子里尝试填一个数字
		for (char ch : availableDigits) {
			int d = ch - '0';
			// 记录状态
			board[i][j] = ch;
			row[i][d] = false;
			col[j][d] = false;
			box[boxIndex(i, j)][d] = false;
			// 搜索下一个位置
			if (dfs(board)) return true;
			// 恢复状态
			board[i][j] = '.';
			row[i][d] = true;
			col[j][d] = true;
			box[boxIndex(i, j)][d] = true;
		}
		return false;
	}

	// 找可能性最小的格子
	pair<pair<int, int>, vector<char>> findMinProbability(vector<vector<char>>& board) {
		int minProbability = 10;
		pair<int, int> pos{-1, -1};
		vector<char> availableDigits;
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') continue;
				auto availDigits = getAvailableDigits(i, j);
				if (availDigits.size() < minProbability) {
					minProbability = availDigits.size();
					pos = {i, j};
					availableDigits = availDigits;
				}
			}
		}
		return {pos, availableDigits};
	}
	// 返回格子(i,j)的所有可以填的数字
	vector<char> getAvailableDigits(int i, int j) {
		vector<char> availableDigits;
		for (char ch = '1'; ch <= '9'; ++ch) {
			int d = ch - '0';
			if (row[i][d] && col[j][d] && box[boxIndex(i, j)][d])
				availableDigits.push_back(ch);
		}
		return availableDigits;
	}
	int boxIndex(int i, int j) {
		return (i/3)*3+j/3;
	}

private:
	// 用于检查可能性:
	bool row[9][10]; // row[i][d]表示第i行上填d的可能性
	bool col[9][10]; // col[j][d]表示第j列上填d的可能性
	bool box[9][10]; // box[b][d]表示第b个盒子里填d的可能性
};
//leetcode submit region end(Prohibit modification and deletion)
