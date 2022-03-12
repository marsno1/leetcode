#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)

// Definition for a Node.
/*class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};*/


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr)
            return {};
        unordered_map<int, vector<int>> m; // level to values
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto element = q.front();
            q.pop();
            Node *node = element.first;
            int level = element.second;
            m[level].push_back(node->val);
            for (Node *child : node->children) {
                q.push({child, level + 1});
            }
        }

        vector<vector<int>> ans(m.size());
        for (auto & p : m) {
            ans[p.first] = p.second;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
