#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 有向图+拓扑排序
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        in_degree.resize(numCourses, 0);
        // 构建邻接链表，初始化入度
        for (auto & pre : prerequisites) {
            int ai = pre[0];
            int bi = pre[1];
            graph[bi].push_back(ai);
            ++in_degree[ai];
        }
        // BFS拓扑排序
        queue<int> q;
        for (int i = 0; i < in_degree.size(); ++i) {
            // 从入度为0的点开始访问
            if (in_degree[i] == 0)
                q.push(i);
        }
        int visited_nums = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            ++visited_nums;
            for (int y : graph[x]) {
                --in_degree[y];
                if (in_degree[y] == 0)
                    q.push(y);
            }
        }
        return visited_nums == numCourses;
    }

private:
    vector<vector<int>> graph;
    vector<int> in_degree;
};
//leetcode submit region end(Prohibit modification and deletion)
