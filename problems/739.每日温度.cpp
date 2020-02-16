/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        int j;
        for (int i = 0; i < T.size(); ++i) {
            while ((j = s.top()) != -1 && T[i] > T[j]) {
                s.pop();
                ans[j] = i - j;
            }
            s.push(i);
        }

        while ((j = s.top())!= -1) {
            s.pop();
            ans[j] = 0;
        }
        return ans;
    }
};
// @lc code=end

