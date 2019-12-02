/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
struct element {
    int count;
    int value;
};

// 递增序(less)是最大值优先
// 递减序(greater)是最小值优先
// 这里应该实现递减序
class Comparison {
public:
    bool operator() (const element& l, const element &r) const {
        return l.count > r.count;
    }
};

class Solution {
public:
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int, int> m;
    //     priority_queue<element, std::vector<element>, Comparison> q;
    //     for (int i = 0; i < nums.size(); ++i) {
    //         ++m[nums[i]];
    //     }
    //     int i = 0;
    //     for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
    //         struct element e;
    //         e.value = it->first;
    //         e.count = it->second;
    //         q.push(e);
    //         if (i >= k) {
    //             q.pop();
    //         }
    //         ++i;
    //     }
    //     vector<int> ans(q.size());
    //     i = 0;
    //     while (!q.empty()) {
    //         struct element e = q.top();
    //         ans[i++] = e.value;
    //         q.pop();
    //     }
    //     return ans;
    // }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        typedef pair<int, int> Pair;
        // 递增序(less)是最大值优先
        // 递减序(greater)是最小值优先
        // 这里应该实现递减序
        priority_queue<Pair, vector<Pair>, greater<Pair>> q;
        for (int i = 0; i < nums.size(); ++i) {
            ++m[nums[i]];
        }
        int i = 0;
        for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
            q.push(make_pair(it->second, it->first));
            if (i >= k) {
                q.pop();
            }
            ++i;
        }
        vector<int> ans(q.size());
        for (i = 0; !q.empty(); i++) {
            ans[i] = q.top().second;
            q.pop();
        }
        return ans;
    }
};
// @lc code=end

