/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
#include <vector>
class Solution {
    vector<int> color;
public:
    bool isBipartite(vector<vector<int>>& graph) {
        color.resize(graph.size(), 0); // A,B两组分别着色为1和-1
        for (int i = 0; i < graph.size(); ++i) {
            if (color[i] == 0) {
                color[i] = 1;
                if (dfs(graph, i) == false) {
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>>& graph, int u) {
        int v;
        for (int j = 0; j < graph[u].size(); ++j) {
            v = graph[u][j]; // 与u相邻的顶点v
            if (color[v] == 0) { //邻接点未着色
                color[v] = - color[u];
                if(dfs(graph, v) == false) return false;
            } else if (color[v] == color[u]) { //邻接点已着色，且与当前点颜色相同
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

