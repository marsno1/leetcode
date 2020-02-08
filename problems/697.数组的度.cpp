/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

// @lc code=start
class Solution {
    struct Node {
        int i;
        int j;
        int count;
        Node(int i, int j, int count): i(i), j(j), count(count) {};
    };
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, Node*> m;
        int max_count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            Node *p = NULL;
           if (m.find(nums[i]) == m.end()) {
               p = new Node(i, i, 1);
               m[nums[i]] = p;
           } else {
               p = m[nums[i]];
               p->j = i;
               ++p->count;
           }
           max_count = max(max_count, p->count);
        }

        int min_len = INT_MAX;
        for (auto a : m) {
            if (a.second->count == max_count) {
                int len = a.second->j - a.second->i + 1;
                min_len = min(min_len, len);
            }
        }
        return min_len;
    }
};
// @lc code=end

