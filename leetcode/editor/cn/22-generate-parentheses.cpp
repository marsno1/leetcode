#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        memo.resize(n + 1);
        return recur(n);
    }

    vector<string> recur(int n) {
        if (!memo[n].empty())
            return memo[n];
        if (n == 0) {
            memo[0] = {""};
            return memo[0];
        }
        // 给一对括号，假设该括号内部有i对括号，该括号右边有j对括号，则有i+j+1=n。
        // 对于i对括号和j对括号，各是一个子问题。
        // 所以，通过枚举i和j，可以得到所有括号组合。
        vector<string> ans;
        for (int i = 0; i <= n - 1; ++i) {
            int j = n - 1 - i;
            const auto & results1 = recur(i);
            const auto & results2 = recur(j);
            for (const string & result1 : results1) {
                for (const string & result2 : results2) {
                    ans.push_back("(" + result1 + ")" + result2);
                }
            }
        }
        memo[n] = ans;
        return ans;
    }

private:
    vector<vector<string>> memo;
};
//leetcode submit region end(Prohibit modification and deletion)
