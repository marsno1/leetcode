/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int m = g.size(), n = s.size();
        int i = 0, j = 0;
        int ans = 0;
        while (i < m && j < n) {
            if (g[i] <= s[j]) {
                ++ans;
                ++i;
                ++j;
            } else {
                ++j;
            }
        }
        return ans;
    }
};
// @lc code=end

