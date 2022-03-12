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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int pre_left, int pre_right, int in_left, int in_right) {
        // 根节点就是前序的第一个节点
        TreeNode *root = new TreeNode(preorder[pre_left]);
        // 在中序中找到根节点的下标
        int mid;
        for(mid = in_left; inorder[mid] != root->val && mid <= in_right; ++mid);
        // 计算左、右子树的节点个数
        int left_nodes_num = mid - in_left; // 左子树的节点个数
        int right_nodes_num = in_right - mid; // 右子树的节点个数
        // 计算左、右子树的前序、中序的左右下标
        int left_pre_left = pre_left + 1; // 左子树的前序的左下标
        int left_pre_right = pre_left + left_nodes_num; // 左子树的前序的右下标
        int right_pre_left = pre_left + left_nodes_num + 1; // 右子树的前序的左下标
        int right_pre_right = pre_right; // 右子树的前序的右下标

        int left_in_left = in_left; // 左子树的中序的左下标
        int left_in_right = mid - 1; // 左子树的中序的右下标
        int right_in_left = mid + 1; // 右子树的中序的左下标
        int right_in_right = in_right; // 右子树的中序的右下标

        if (left_nodes_num > 0)
            root->left = build(preorder, inorder, left_pre_left, left_pre_right, left_in_left, left_in_right);
        if (right_nodes_num > 0)
            root->right = build(preorder, inorder, right_pre_left, right_pre_right, right_in_left, right_in_right);
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
