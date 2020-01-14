/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    // 状态定义：dp[i]表示长度为i的字符串的解码数量
    // 状态转移方程：dp[i]是以下两值之和
    //     (1) dp[i-1] if "s[i-1]"!="0" else 0
    //     (2) dp[i-2] if "s[i-2]s[i-1]"="1"~"26" else 0
    // 初始状态: 
    //     dp[0]=1
    //     dp[1]=1 if "s[1]"!="0" else dp[1]=0
    // 返回: dp[n]
    // int numDecodings(string s) {
    //     int n = s.length();
    //     vector<int> dp(n + 1);
    //     dp[0] = 1;
    //     if (s[0] != '0') {
    //         dp[1] = 1;
    //     }
    //     if (n == 1) return dp[1];

    //     for (int i = 2; i <= n; ++i) {
    //         if (s[i - 1] != '0') {
    //             dp[i] = dp[i-1];
    //         }
    //         if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
    //             dp[i] += dp[i - 2];
    //         }
    //     }
    //     return dp[n];
    // }

    // 递归
    int numDecodings(string s) {
        vector<int> mem(s.length() + 1, -1);
        return f(s, s.length(), mem);
    }

    int f(string& s, int i, vector<int>& mem) {
        if (mem[i] != -1) {
            return mem[i];
        }
        if (i == 0) {
            return 1;
        }
        if (i == 1) {
            if (s[0] != '0') {
                mem[i] = 1;
            } else {
                mem[i] = 0;
            }
        } else {
            mem[i] = 0;
            if (s[i - 1] != '0') {
                mem[i] += f(s, i - 1, mem);
            }
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
                mem[i] += f(s, i - 2, mem);
            }
        }
        return mem[i];
    }
};
// @lc code=end

