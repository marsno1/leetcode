#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		unordered_set<char> row[9];
		unordered_set<char> col[9];
		unordered_set<char> box[9];
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				char ch = board[i][j];
				if (ch == '.') continue;
				if (row[i].find(ch) != row[i].end()) return false;
				row[i].insert(ch);
				if (col[j].find(ch) != col[j].end()) return false;
				col[j].insert(ch);
				int k = (i/3)*3 + (j/3);
				if (box[k].find(ch) != box[k].end()) return false;
				box[k].insert(ch);
			}
		}
		return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
