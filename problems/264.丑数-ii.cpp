/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) {
            return 1;
        }
        priority_queue<long, vector<long>, greater<long>> q;
        q.push(1);
 
        long ans;
        while (n > 0) {
            ans = q.top();
            if (--n == 0) {
                break;
            }
            while (!q.empty() && q.top() == ans) {
                q.pop();
            }
            q.push(ans * 2);
            q.push(ans * 3);
            q.push(ans * 5);
        }
        return ans;
    }
};
// @lc code=end

