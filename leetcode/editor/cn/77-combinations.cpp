#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        recur(1);
        return ans;
    }

    void recur(int i) {
        // 剪枝：如果把剩下的元素全选上也不够k个，就提前终止
        if (result.size() + (n - i + 1) < k)
            return;

        if (result.size() == k) {
            ans.push_back(result);
            return;
        }

        // 不挑选第i个元素
        recur( i + 1);
        // 挑选第i个元素
        result.push_back(i);
        recur( i + 1);
        // 恢复
        result.pop_back();
    }

private:
    vector<vector<int>> ans;
    vector<int> result;
    int n;
    int k;
};
//leetcode submit region end(Prohibit modification and deletion)
