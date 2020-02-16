/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        inOrder(root, k, ans);
        return ans;
    }

    void inOrder(TreeNode* root, int& k, int& ans) {
        if (!root) {
            return;
        }

        inOrder(root->left, k, ans);
        if (--k == 0) {
            ans = root->val;
            return;
        }
        inOrder(root->right, k, ans);
    }
};
// @lc code=end

