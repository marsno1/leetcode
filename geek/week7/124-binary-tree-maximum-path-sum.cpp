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
    // 树形动规
    int maxPathSum(TreeNode* root) {
        // f[i]表示以节点i为根的子树中，路径包含节点i时的最大路径和
        // 最优化目标：所有f[i]中的最大值
        ans = -1e9;
        dfs(root);
        return ans;
    }

    // 函数返回值表示路径饱含节点i和左节点，或者包含节点i和右节点，这两种情况之一时的最大路径和
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int leftMax = dfs(root->left);
        int rightMax = dfs(root->right);
        int a = max(leftMax, 0);
        int b = max(rightMax, 0);
        // 计算函数f[i]
        int rootMax = root->val + a + b;
        ans = max(ans, rootMax);
        return root->val + max(a, b);
    }

private:
    int ans;

    // 第二种思路是：
    // f[i][0]表示不选节点i时，以i为根的子树的最大路径和
    // f[i][1]和f[i][2]表示选节点i时，以i为根的子树的最大路径和，其中：
    //      f[i][1]表示路径跨过节点i，包含i和它的左右子节点
    //      f[i][2]表示路径要么包含i及左子节点，要么包含i及右子节点，要么只包含i
    // 最优化目标：max(f[root][0],f[root][1],f[root][2])
    // 这个实现较复杂!!!
//    int maxPathSum(TreeNode* root) {
//        f[nullptr] = vector<int>(3, 0);
//        maxVal = -1e9;
//        dfs(root);
//        int ans = max(f[root][0], max(f[root][1], f[root][2]));
//        return ans == 0 ? maxVal : ans;
//    }
//
//    void dfs(TreeNode* root) {
//        if (!root)
//            return;
//        f[root] = vector<int>(3, 0);
//        maxVal = max(maxVal, root->val);
//        dfs(root->left);
//        dfs(root->right);
//        // 决策1：选当前节点有2种情况
//        // f[i][1]：left、root、right都在路径上，
//        //      root->val + max(f[left][2],f[right][2])
//        // f[i][2]：root在路径上，并且left或right之一在路径上，或left和right都不在路径上，
//        //      root-val 或者 root->val + max(f[left][2],f[right][2]);
//        int case1 = root->val + f[root->left][2] + f[root->right][2];
//        int case2 = max(root->val, root->val + max(f[root->left][2], f[root->right][2]));
//        f[root][1] = case1;
//        f[root][2] = case2;
//
//        // 决策2：不选当前节点
//        // f[i][0]：取left选或不选、right选或不选其中的最大值
//        int leftMax = max(f[root->left][0], max(f[root->left][1], f[root->left][2]));
//        int rightMax = max(f[root->right][0], max(f[root->right][1], f[root->right][2]));
//        f[root][0] = max(leftMax, rightMax);
//    }
//
//private:
//    unordered_map<TreeNode*, vector<int>> f;
//    int maxVal;
};
//leetcode submit region end(Prohibit modification and deletion)
