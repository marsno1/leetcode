/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inOrder(root, v);
        int l = 0, r = v.size() - 1;
        while (l < r) {
            int sum = v[l] + v[r];
            if (sum == k) {
                return true;
            } else if (sum < k) {
                ++l;
            } else {
                --r;
            }
        }
        return false;
    }

    void inOrder(TreeNode* root, vector<int>& v) {
        if (root == NULL) return;

        if (root->left) {
            inOrder(root->left, v); 
        }

        v.push_back(root->val);

        if (root->right) {
            inOrder(root->right, v); 
        }
    }
};
// @lc code=end

