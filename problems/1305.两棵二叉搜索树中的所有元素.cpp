/*
 * @lc app=leetcode.cn id=1305 lang=cpp
 *
 * [1305] 两棵二叉搜索树中的所有元素
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        inOrder(root1, v1);
        inOrder(root2, v2);
 
        int m = v1.size(), n = v2.size();
        vector<int> ans;
        int i = 0, j = 0;
        while (true) {
            if (i == m && j == n) {
                break;
            }
            if (j == n) {
                ans.push_back(v1[i]);
                ++i;
                continue;
            }
            if (i == m) {
                ans.push_back(v2[j]);
                ++j;
                continue;
            }
            if (v1[i] <= v2[j]) {
                ans.push_back(v1[i]);
                ++i;
            } else if (v1[i] > v2[j]) {
                ans.push_back(v2[j]);
                ++j;
            }
        }
       
        return ans;
    }

    void inOrder(TreeNode* root, vector<int>& v) {
        if (!root) {
            return;
        }

        inOrder(root->left, v);
        v.push_back(root->val); 
        inOrder(root->right, v);
    }
};
// @lc code=end

