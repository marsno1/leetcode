#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return root;
        if (root->val == key) {
            if (root->left == nullptr) return root->right;
            if (root->right == nullptr) return root->left;
            // 寻找后继(此时右子树肯定不为空)
            // 实现1: 递归方式
            int successor;
            root->right = toLeft(root->right, successor);
            // 替换被删除的节点
            root->val = successor;
            // 实现2： 循环方式
//            TreeNode *next = root->right;
//            while (next->left) next = next->left;
//            root->right = deleteNode(root->right, next->val);
//            // 替换被删除的节点
//            root->val = next->val;
        }
        else if (key < root->val) { // 往左找
            root->left = deleteNode(root->left, key);
        } else { // 往右找
            root->right = deleteNode(root->right, key);
        }
        return root;
    }

    TreeNode* toLeft(TreeNode* root, int& successor) {
        if (root->left) {
            root->left = toLeft(root->left, successor);
            return root;
        }
        else {
            successor = root->val;
            return root->right;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
