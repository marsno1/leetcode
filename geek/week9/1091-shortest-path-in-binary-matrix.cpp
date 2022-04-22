#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
        int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
        queue<pair<int, int>> q;
        grid[0][0] = 1;
        q.push({0,0});
        while(!q.empty()) {
            pair<int, int> point = q.front();
            q.pop();

            int x = point.first;
            int y = point.second;
            if (x == n-1 && y == n-1) {
                return grid[x][y];
            }

            for (int i = 0; i < 8; ++i) {
                int next_x = x + dx[i];
                int next_y = y + dy[i];
                if (next_x >= 0 && next_x < n &&
                    next_y >= 0 && next_y < n &&
                    grid[next_x][next_y] == 0) {
                    grid[next_x][next_y] = grid[x][y] + 1;
                    q.push({next_x, next_y});
                }
            }
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
