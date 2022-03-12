#include "include/headers.h"
using namespace std;

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
    // 实现一(推荐)：
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p = p;
        this->q = q;
        ans = nullptr;
        dfs(root);
        return ans;
    }

    // 返回值的两个bool值，分别表示当前子树是否包含p，是否包含q
    pair<bool, bool> dfs(TreeNode* root) {
        if (root == nullptr)
            return {false, false};
        pair<bool, bool> left_result = dfs(root->left);
        pair<bool, bool> right_result = dfs(root->right);
        pair<bool, bool> result;
        result.first = left_result.first || right_result.first || root == p;
        result.second = left_result.second || right_result.second || root == q;
        if (result.first && result.second && ans == nullptr) {
            ans = root;
        }
        return result;
    }

private:
    TreeNode *p;
    TreeNode *q;
    TreeNode *ans;

    // 实现二：
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if (root == p || root == q) return root;
//
//        TreeNode *node1 = nullptr;
//        TreeNode *node2 = nullptr;
//        if (root->left)
//            node1 = lowestCommonAncestor(root->left, p, q);
//        if (root->right)
//            node2 = lowestCommonAncestor(root->right, p, q);
//        if (node1 && node2)
//            return root;
//        if (node1)
//            return node1;
//        if (node2)
//            return node2;
//        return nullptr;
//    }
};
//leetcode submit region end(Prohibit modification and deletion)
