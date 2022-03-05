#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // 把障碍物坐标放到集合里
        unordered_set<unsigned long long> obs_set;
        for (const vector<int> & obs : obstacles) {
            unsigned long long hash = calcHash(obs);
            obs_set.insert(hash);
        }

        int dir = 0; // 0,1,2,3分别表示北、东、南、西
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0; // 起始坐标为原点
        int ans = 0;
        // 依次处理每条命令，判断是否碰到障碍物
        for (int command : commands) {
            if (command == -2) {
                dir = (dir + 3) % 4;
            } else if (command == -1) {
                dir = (dir + 1) % 4;
            } else {
                int nx, ny;
                for (int i = 0; i < command; ++i) {
                    nx = x + dx[dir];
                    ny = y + dy[dir];
                    if (obs_set.count(calcHash({nx, ny})) > 0) {
                        // 碰到障碍物，停止当前的命令
                        break;
                    } else {
                        x = nx;
                        y = ny;
                    }
                }
                // 当前的行进停止时，再更新一下最大距离
                ans = max(ans, x * x + y * y);
            }
        }
        return ans;
    }

    unsigned long long calcHash(const vector<int> & obs) {
        unsigned long long hash1 = (obs[0] & 0xff | obs[0] & 0xff00 | obs[0] & 0xff0000 | obs[0] & 0xff000000);
        unsigned long long hash2 = (obs[1] & 0xff | obs[1] & 0xff00 | obs[1] & 0xff0000 | obs[1] & 0xff000000);
        unsigned long long hash = (hash1 << 32) | hash2;
        return hash;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
