#include "include/headers.h"
using namespace std;

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
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q) return root;

        TreeNode *node1 = nullptr;
        TreeNode *node2 = nullptr;
        if (root->left)
            node1 = lowestCommonAncestor(root->left, p, q);
        if (root->right)
            node2 = lowestCommonAncestor(root->right, p, q);
        if (node1 && node2)
            return root;
        if (node1)
            return node1;
        if (node2)
            return node2;
        return nullptr;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
