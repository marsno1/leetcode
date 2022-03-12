#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // 把原二权树看成一棵具有空的叶节点的树，把每个空节点序列化成null。
    // 使用前序遍历的结果作为序列化字符串，使用递归作反序列化。

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "null";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        while (true) {
            int j = data.find(",", i);
            if (j == string::npos) {
                values.push_back(data.substr(i, data.length() - i));
                break;
            }
            values.push_back(data.substr(i, j - i));
            i = j + 1;
        }

        curr = 0;
        return recur();
    }
    TreeNode* recur() {
        if (values[curr] == "null") {
            ++curr;
            return nullptr;
        }
        TreeNode *root = new TreeNode(atoi(values[curr].c_str()));
        ++curr;
        root->left = recur();
        root->right = recur();
        return root;
    }

private:
    vector<string> values;
    int curr;
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
//leetcode submit region end(Prohibit modification and deletion)
