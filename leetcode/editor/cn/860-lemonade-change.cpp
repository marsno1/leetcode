#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 贪心算法
    bool lemonadeChange(vector<int>& bills) {
        m[5] = m[10] = m[20] = 0;
        for (int bill : bills) {
            ++m[bill];
            if (bill > 5 && !exchange(bill - 5)) {
                return false;
            }
        }
        return true;
    }

    bool exchange(int amount) {
        for (int x : {20, 10, 5}) {
            while (m[x] > 0 && amount >= x) {
                amount -= x;
                --m[x];
            }
        }
        return amount == 0;
    }

private:
    unordered_map<int, int> m;
};
//leetcode submit region end(Prohibit modification and deletion)
