#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        this->end = end;

        for (string & seq : bank) {
            depth[seq] = 0;
        }
        ans = -1;
        // 使用DFS
//        depth[start] = 1; // 标记为已访问过
//        dfs(start, 1);
        // 使用BFS
        depth[start] = 0; // 标记为到达的步数为0
        bfs(start);
        return ans;
    }

    // depth: 用来记录是否访问过某个序列，以及到达该序列的变化次数
    void bfs(string start) {
        static const char gene[4] = {'A', 'C', 'G', 'T'};
        queue<string> q;
        q.push(start);
        while (!q.empty()) {
            start = q.front();
            q.pop();
            int lastDepth = depth[start];
            for (int i = 0; i < 8; ++i) {
                char oldChar = start[i];
                for (int j = 0; j < 4; ++j) {
                    if (gene[j] == start[i]) continue; // 序列没有发生变化
                    start[i] = gene[j]; // 变化一个字符，得到一个新的序列
                    if (depth.find(start) == depth.end()) continue; // 新序列没在基因库里
                    if (depth[start] > 0) continue; // 已经搜索过该序列，那么当前搜索路径肯定比之前的更长，所以终止当前搜索
                    depth[start] = lastDepth + 1;
                    if (start == end) { // 找到终点序列
                        ans = depth[start];
                        return;
                    }
                    q.push(start);
                }
                start[i] = oldChar; // 恢复位置i的字符
            }
        }
    }

    // start: 当前阶段处理的序列
    // step: 当前阶段是第几次变化
    // depth: 只用来记录是否访问过某个序列，不记录到达该序列的变化次数
    void dfs(string start, int step) {
        static const char gene[4] = {'A', 'C', 'G', 'T'};
        for (int i = 0; i < 8; ++i) {
            char oldChar = start[i];
            for (int j = 0; j < 4; ++j) {
                if (gene[j] == start[i]) continue; // 序列没有发生变化
                start[i] = gene[j]; // 变化一个字符，得到一个新的序列
                if (depth.find(start) == depth.end()) continue; // 新序列没在基因库里
                // 深度搜索结束的条件：如果当前序列无法生成"新的"合法的序列，则不再进入下一个阶段
                if (depth[start] > 0) continue; // 没生成新的序列：新序列在基因库里，而且已经访问过了
                depth[start] = 1; // 设置一个非0值即可
                if (start == end) {
                    // 每当搜索到一个终点序列时，记录下当前进行了多少次变化，更新最小变化次数
                    ans = ans == -1 ? step : min(ans, step);
                }
                dfs(start, step + 1);
            }
            start[i] = oldChar; // 恢复位置i的字符
        }
    }

private:
    string end;
    unordered_map<string, int> depth; // 标记某个序列是否访问过，及到达该序列的变化次数
    int ans;
};
//leetcode submit region end(Prohibit modification and deletion)
