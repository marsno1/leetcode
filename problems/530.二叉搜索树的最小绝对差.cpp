/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    TreeNode *prev;
    int min_diff;
public:
    int getMinimumDifference(TreeNode* root) {
        min_diff = INT_MAX;
        inOrder(root);
        return min_diff;
    }

    void inOrder(TreeNode* root) {
        if (!root) {
            return;
        }

        if (root->left) {
            inOrder(root->left);
        }

        if (prev) {
            min_diff = min(min_diff, abs(root->val - prev->val));
        }
        prev = root;

        if (root->right) {
            inOrder(root->right);
        }
    }
};
// @lc code=end

