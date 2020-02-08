/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    // bits[i]可以由bits[i&(i-1)]推导出来，因为i&(i-1)表示把i的最后一个1抹掉了，所以在bits[i&(i-1)]的基础上加1即可
    // vector<int> countBits(int num) {
    //     vector<int> bits(num + 1);
    //     bits[0] = 0;
    //     for (int i = 1; i <= num; ++i) {
    //         bits[i] = bits[i&(i-1)] + 1;
    //     }
    //     return bits;
    // }

    // bits[i]可以由bits[i>>1]推导出来，根据i的最后一位是1或0，分别加1或加0
    vector<int> countBits(int num) {
        vector<int> bits(num + 1);
        bits[0] = 0;
        for (int i = 1; i <= num; ++i) {
            bits[i] = bits[i >> 1] + (i & 1);
        }
        return bits;
    }
};
// @lc code=end

