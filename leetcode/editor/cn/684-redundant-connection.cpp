#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // 确定最大顶点的编号，用于初始化邻接链表
        int max_vertex = 0;
        for (const auto & edge : edges)
            max_vertex = max(max_vertex, max(edge[0], edge[1]));
        graph.resize(max_vertex + 1);
        visited.resize(max_vertex + 1, false);

        // 每加入一条新的边，就判断一次图中是否有环；
        // 如果有环，则新加入的边就是所求的答案。
        for (const auto & edge : edges) {
            // 逐个添加每条边，构造出一个图
            int x = edge[0];
            int y = edge[1];
            graph[x].push_back(y);
            graph[y].push_back(x);

            // 每次DFS之前清空visited
            for (int i = 0; i < visited.size(); ++i)
                visited[i] = false;
            bool has_cycle = dfs(x, 0);
            if (has_cycle) {
                return edge;
            }
        }
        return {};
    }

    // 代码模板：判断图中是否有环
    bool dfs(int x, int parent) {
        visited[x] = true;
        for (int y : graph[x]) {
            if (y == parent)
                continue;
            if (visited[y])
                return true;
            else {
                bool has_cycle = dfs(y, x);
                if (has_cycle)
                    return true;
            }
        }
        return false;
    }

private:
    vector<vector<int>> graph; //邻接链表
    vector<bool> visited;
};
//leetcode submit region end(Prohibit modification and deletion)
