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
    bool isValidBST(TreeNode* root) {
        return recur(root, INT_MIN, INT_MAX);
    }

    bool recur(TreeNode *root, long left, long right) {
        if (root == nullptr)
            return true;
        if (root->val < left || root->val > right)
            return false;

        bool is_left_valid = recur(root->left, left, (long)root->val - 1);
        bool is_right_valid = recur(root->right, (long)root->val + 1, right);

        return is_left_valid && is_right_valid;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
