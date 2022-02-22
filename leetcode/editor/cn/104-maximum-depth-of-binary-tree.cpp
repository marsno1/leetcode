#include "include/headers.h"
using namespace std;

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
    // DFS
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        int left_max_depth = maxDepth(root->left);
        int right_max_depth = maxDepth(root->right);

        return max(left_max_depth, right_max_depth) + 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
