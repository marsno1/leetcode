/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indegree(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            int a = prerequisites[i][1];
            int b = prerequisites[i][0];
            adj[a].push_back(b);
            ++indegree[b];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            order.push_back(v);
            for (int i = 0; i < adj[v].size(); ++i) {
                int u = adj[v][i];
                if (--indegree[u] == 0) {
                    q.push(u);
                }
            }
        }
        
        return order.size() == numCourses ? order : vector<int>();
    }
};
// @lc code=end

