/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    int duplicates;
    int max_duplicates;
    vector<int> ans;
public:
    vector<int> findMode(TreeNode* root) {
        prev = NULL;
        duplicates = 0;
        max_duplicates = 0;
        inOrder(root);
        return ans;
    }

    void inOrder(TreeNode* root) {
        if (!root) {
            return;
        }

        inOrder(root->left);

        if (prev && root->val == prev->val) {
            ++duplicates;
        } else {
            duplicates = 1;
        }
        if (duplicates > max_duplicates) {
            max_duplicates = duplicates;
            ans.resize(1);
            ans[0] = root->val;
        } else if (duplicates == max_duplicates) {
            ans.push_back(root->val);
        }
        prev = root;
        
        inOrder(root->right);
    }
};
// @lc code=end

