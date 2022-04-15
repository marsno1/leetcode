#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
	struct Node {
		int count;
		unordered_map<char, Node*> children;
	};

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		root = new Node{.count = 0};
		// 初始化trie树
		for (const string & word : words) {
			insert(word);
		}

		m = board.size();
		n = board[0].size();
		visited.resize(m, vector<bool>(n, false));
		// 搜索网格
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				char ch = board[i][j];
				if (root->children.find(ch) == root->children.end())
					continue;
				visited[i][j] = true;
				dfs(board, i, j, root->children[ch]);
				visited[i][j] = false;
			}
		}
		return vector<string>(ans.begin(), ans.end());
    }

	void dfs(vector<vector<char>>& board, int x, int y, Node* curr) {
		static const int dx[4] = {0, 0, 1, -1};
		static const int dy[4] = {1, -1, 0, 0};

		char ch = board[x][y];
		path.push_back(ch);
		// 找到一个单词
		if (curr->count > 0) {
			ans.insert(path);
		}

		for (int d = 0; d < 4; ++d) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n)
				continue;
			if (visited[nx][ny])
				continue;
			// 同时检查是否在trie树里
			char ch = board[nx][ny];
			if (curr->children.find(ch) == curr->children.end()) {
				continue;
			}

			visited[nx][ny] = true;
			dfs(board, nx, ny, curr->children[ch]);
			visited[nx][ny] = false;
		}
		path.pop_back();
	}

private:
	Node *root;

	int m, n;
	vector<vector<bool>> visited;
	string path; // 记录dfs的搜索路径
	unordered_set<string> ans;

	void insert(string word) {
		find(word, true, false);
	}

	bool find(string s, bool isInsert, bool isPrefix) {
		Node *curr = root;
		for (const char ch : s) {
			if (curr->children.find(ch) == curr->children.end()) {
				if (isInsert) {
					curr->children[ch] = new Node{.count = 0};
				} else {
					// 没找到
					return false;
				}
			}
			curr = curr->children[ch];
		}
		if (isInsert)
			++curr->count;
		if (isPrefix)
			return true;
		return curr->count > 0;
	}
};
//leetcode submit region end(Prohibit modification and deletion)
