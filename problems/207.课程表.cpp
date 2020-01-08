/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    // BFS
    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    //     vector<vector<int>> adj(numCourses, vector<int>());
    //     vector<int> indegree(numCourses);
    //     for (int i = 0; i < prerequisites.size(); ++i) {
    //         int a = prerequisites[i][1];
    //         int b = prerequisites[i][0];
    //         adj[a].push_back(b);
    //         ++indegree[b];
    //     }

    //     queue<int> q;
    //     for (int i = 0; i < numCourses; ++i) {
    //         if (indegree[i] == 0) {
    //             q.push(i);
    //         }
    //     }

    //     int visited = 0;
    //     while (!q.empty()) {
    //         int v = q.front();
    //         q.pop();
    //         ++visited;
    //         for (int i = 0; i < adj[v].size(); ++i) {
    //             int u = adj[v][i];
    //             if (--indegree[u] == 0) {
    //                 q.push(u);
    //             }
    //         }
    //     }
        
    //     return visited == numCourses;
    // }

    // DFS
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indegree(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            int a = prerequisites[i][1];
            int b = prerequisites[i][0];
            adj[a].push_back(b);
            ++indegree[b];
        }

        // 1: visited by self, -1: visisted by others
        vector<int> visited(numCourses);
        for (int i = 0; i < numCourses; ++i) {
            if (DFS(adj, i, visited)) {
                return false;
            }
        }
        return true;
    }

    // true: cyclic, false: acyclic
    bool DFS(vector<vector<int>>& adj, int v, vector<int>& visited) {
        if (visited[v] == 1) {
            return true;
        }

        visited[v] = 1;
        for (int i = 0; i < adj[v].size(); ++i) {
            if (DFS(adj, adj[v][i], visited)) {
                return true;
            }
        }
        visited[v] = -1;
        return false;
    }
};
// @lc code=end

