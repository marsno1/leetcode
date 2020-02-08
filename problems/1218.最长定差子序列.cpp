/*
 * @lc app=leetcode.cn id=1218 lang=cpp
 *
 * [1218] 最长定差子序列
 */

// @lc code=start
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int, int> m;
        int ans = 0;
        for (int i =0; i < n; ++i) {
            int curr = arr[i];
            int prev = arr[i] - difference;
            int len = m[prev] + 1;
            m[curr] = len;
            ans = max(ans, len);
        }
        return ans;
    }
};
// @lc code=end

