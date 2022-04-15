#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Trie {
public:
    Trie() {
		root = new Node{.count = 0, .children= {nullptr}};
    }
    
    void insert(string word) {
		find(word, true, false);
    }

	// 查找是否存在word
    bool search(string word) {
		return find(word, false, false);
    }

	// 查找是否存在前缀
    bool startsWith(string prefix) {
		return find(prefix, false, true);
    }

	bool find(string s, bool isInsert, bool isPrefix) {
		Node *curr = root;
		for (const char ch : s) {
			int id = ch - 'a';
			if (curr->children[id] == nullptr) {
				if (isInsert) {
					curr->children[id] = new Node{.count = 0, .children= {nullptr}};
				} else {
					// 没找到
					return false;
				}
			}
			curr = curr->children[id];
		}
		if (isInsert)
			++curr->count;
		if (isPrefix)
			return true;
		return curr->count > 0;
	}

private:
	struct Node {
		int count;
		struct Node *children[26];
	};
	Node *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
//leetcode submit region end(Prohibit modification and deletion)
