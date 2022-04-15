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
    int rob(TreeNode* root) {
        // f[i][j]表示对于以节点i为根的子树，决策为j时的最高偷窃金额，j有两种值：
        // f[i][0]表示不偷节点i，则子节点可偷或不偷
        // f[i][1]表示偷节点i，则子节点不能偷
        f[nullptr] = vector<int>(2, 0);
        dfs(root);
        return max(f[root][0], f[root][1]);
    }
    void dfs(TreeNode* root) {
        if (!root)
            return;
        f[root] = vector<int>(2, 0);
        dfs(root->left);
        dfs(root->right);
        f[root][0] = max(f[root->left][0], f[root->left][1]) + max(f[root->right][0], f[root->right][1]);
        f[root][1] = root->val + f[root->left][0] + f[root->right][0];
    }

private:
    unordered_map<TreeNode*, vector<int>> f;
};
//leetcode submit region end(Prohibit modification and deletion)
