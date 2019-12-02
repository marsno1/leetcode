/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    TreeNode *prev = NULL;
public:
    // bool isValidBST(TreeNode* root) {
    //     if (root == NULL) return true;
    //     if (isValidBST(root->left) == false) {
    //         return false;
    //     }
    //     if (prev && root->val <= prev->val) {
    //         return false;
    //     }
    //     prev = root;
    //     if (isValidBST(root->right) == false) {
    //         return false;
    //     }
    //     return true;
    // }

    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }

    bool isValid(TreeNode* root, long low, long high) {
        if (root == NULL) return true;
        if (!(root->val > low && root->val < high)) return false;

        return isValid(root->left, low, root->val) && 
                isValid(root->right, root->val, high);
    }
};
// @lc code=end

