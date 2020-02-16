/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 */

// @lc code=start
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return NULL;
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left) {
                // 找前驱节点
                TreeNode *pre = predecessor(root);
                root->val = pre->val;
                // 在左子树中删除前驱节点
                root->left = deleteNode(root->left, pre->val);
            } else if (root->right) {
                // 找后继节点
                TreeNode *suc = successor(root);
                root->val = suc->val;
                // 在右子树中删除后继节点
                root->right = deleteNode(root->right, suc->val);
            } else {
                return NULL;
            }
        }
        return root;
    }

    TreeNode* predecessor(TreeNode* root) {
        root = root->left;
        while (root->right) {
            root = root->right;
        }
        return root;
    }

    TreeNode* successor(TreeNode* root) {
        root = root->right;
        while (root->left) {
            root = root->left;
        }
        return root;
    }
};
// @lc code=end

