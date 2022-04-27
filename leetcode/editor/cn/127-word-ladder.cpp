#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
	// BFS
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		for (string word : wordList)
			wordDict.insert(word);
#if 0
		// 实现一的调用：
		return bfs(beginWord, endWord);
#endif
		// 实现二的调用：
		return bidirectionalBfs(beginWord, endWord);
    }

#if 0
	// 实现一：BFS
	int bfs(string beginWord, string endWord) {
 		if (wordDict.find(endWord) == wordDict.end()) return 0;
		q.push(beginWord);
		depth[beginWord] = 1;
		while (!q.empty()) {
			string word = q.front();
			q.pop();
			for (int i = 0; i < word.length(); ++i) {
				for (char ch = 'a'; ch <= 'z'; ++ch) {
					if (ch == word[i]) continue; // 不能与当前单词相同
					// 产生一个新单词
					string newWord = word;
					newWord[i] = ch;
					if (wordDict.find(newWord) == wordDict.end()) continue; // 新单词不在字典里
					if (depth.find(newWord) != depth.end()) continue; // 如果已经找过了，则当前搜索肯定不是最短步数
					depth[newWord] = depth[word] + 1;
					cout << newWord << ":" << depth[newWord] << endl;
					if (newWord == endWord) return depth[newWord];
					q.push(newWord);
				}
			}
		}
		return 0;
	}
private:
	unordered_set<string> wordDict;
	unordered_map<string, int> depth; // 记录到达每个单词的步数
	queue<string> q;
#endif

	// 实现二(优化版)：双向BFS
	int bidirectionalBfs(string beginWord, string endWord) {
		if (wordDict.find(endWord) == wordDict.end()) return 0;
		qBegin.push(beginWord);
		qEnd.push(endWord);
		depthBegin[beginWord] = 1;
		depthEnd[endWord] = 1;
		while (!qBegin.empty() || !qEnd.empty()) {
			int ret;
			// 从beginWord扩展一步
			ret = expand(qBegin, depthBegin, depthEnd);
			if (ret != -1) return ret;
			// 从endWord扩展一步
			ret = expand(qEnd, depthEnd, depthBegin);
			if (ret != -1) return ret;
		}
		return 0;
	}

	int expand(queue<string> & q, unordered_map<string, int> & depth, unordered_map<string, int> & otherDepth) {
		if (q.empty()) return -1;
		int qSize = q.size();
		// 要队列中当前的所有单词都扩展一步(注意不是只扩展一个单词)
		for (int k = 0; k < qSize; ++k) {
			string word = q.front();
			q.pop();
			for (int i = 0; i < word.length(); ++i) {
				for (char ch = 'a'; ch <= 'z'; ++ch) {
					if (ch == word[i]) continue; // 不能与当前单词相同
					// 产生一个新单词
					string newWord = word;
					newWord[i] = ch;
					if (wordDict.find(newWord) == wordDict.end()) continue; // 新单词不在字典里
					if (depth.find(newWord) != depth.end()) continue; // 如果已经找过了，则当前搜索肯定不是最短步数
					// 新单词已经存在于对方到达的集合中
					if (otherDepth.find(newWord) != otherDepth.end()) {
						return depth[word] + otherDepth[newWord];
					}
					depth[newWord] = depth[word] + 1;
					q.push(newWord);
				}
			}
		}
		return -1;
	}
private:
	unordered_set<string> wordDict;
	unordered_map<string, int> depthBegin, depthEnd; // 记录到达每个单词的步数
	queue<string> qBegin, qEnd;
};
//leetcode submit region end(Prohibit modification and deletion)
