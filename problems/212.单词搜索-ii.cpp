/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
struct Node {
    Node* link[26];
    bool found; // false: haven't been found, true: have been found
    string word;

    Node(): found(false), word("") {
        for (int i = 0; i < 26; ++i)
            link[i] = NULL;
    }
};

class Solution {
    vector<string> ans;
public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        // 构建Trie树
        Node *root = new Node;
        Node *p;
        for (int i = 0; i < words.size(); ++i) {
            p = root;
            for (int j = 0; j < words[i].size(); ++j) {
                int id = words[i][j] - 'a';
                if (p->link[id] == NULL) {
                    p->link[id] = new Node;
                }
                p = p->link[id];
            }
            p->word = words[i];
        }

        // 搜索单词 
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                // 开始一次搜索
                dfs(board, i, j, root);
            }
        }
        
        return ans;
    }

    void dfs(vector<vector<char> >& board, int i, int j, Node* p) {
        char c = board[i][j];
        int id = c - 'a';
        // 在一次搜索中，'*'标记该搜索路径上的字符已经被访问过，不能反复访问
        if (c == '*' || p->link[id] == NULL) return;
    
        p = p->link[id];
        if (p->word.size() > 0 && !p->found) {
            ans.push_back(p->word);
            p->found = true;
        }

        board[i][j] = '*';
        if (i - 1 >= 0) { // up
            dfs(board, i - 1, j, p);
        }
        if (i + 1 < board.size()) { // down
            dfs(board, i + 1, j, p);
        }
        if (j - 1 >= 0) { // left
            dfs(board, i, j - 1, p);
        }
        if (j + 1 < board[0].size()) { // right
            dfs(board, i, j + 1, p);
        }
        board[i][j] = c;
    }
};
// @lc code=end

