#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        bool carry = true;
        for (int i = n - 1; i >= 0 && carry; --i) {
            ++digits[i];
            digits[i] = digits[i] % 10;
            carry = digits[i] == 0 ? true : false;
        }
        if (carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
