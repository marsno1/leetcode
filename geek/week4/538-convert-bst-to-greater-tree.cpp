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
    TreeNode* convertBST(TreeNode* root) {
        inorder(root);
        int suffixSum = 0; // 后缀和
        for (int i = orderedList.size() - 1; i >= 0; --i) {
            int currVal = orderedList[i]->val;
            orderedList[i]->val += suffixSum;
            suffixSum += currVal;
        }
        return root;
    }

    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;
        inorder(root->left);
        orderedList.push_back(root);
        inorder(root->right);
    }

private:
    vector<TreeNode*> orderedList;
};
//leetcode submit region end(Prohibit modification and deletion)
