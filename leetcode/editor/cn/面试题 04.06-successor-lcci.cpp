#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        return getNext(root, p->val);
    }

    // 求后继的一般化的函数
    TreeNode* getNext(TreeNode* root, int val) {
        // 先检索到val
        TreeNode *curr = root;
        TreeNode *ans = nullptr;
        while (curr) {
            if (curr->val == val) {
                // 找到了val，然后找它的后继：从右子树一路向左
                if (curr->right) {
                    ans = curr->right;
                    while (ans->left)
                        ans = ans->left;
                }
                break;
            }
            if (val < curr->val) {
                // 记录从根节点到val的路径上，比val大的最小值
                if (ans == nullptr || ans->val > curr->val) {
                    ans = curr;
                }
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
