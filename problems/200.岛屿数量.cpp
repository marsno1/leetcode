/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
// UnionFindSet
class UFS
{
    vector<int> roots;
    vector<int> rank;
    int count; // number of distinct roots
public:
    UFS(int n) : roots(n), rank(n), count(n)
    {
        MakeUFS();
    }

    int Count()
    {
        return count;
    }

    void MakeUFS()
    {
        for (int i = 0; i < roots.size(); ++i)
        {
            roots[i] = i;
        }
    }
    int Find(int x)
    {
        int root = x;
        while (root != roots[root])
        {
            root = roots[root];
        }
        while (x != root)
        {
            int parent = roots[x];
            roots[x] = root;
            x = parent;
        }
        return root;
    }

    void Union(int x, int y)
    {
        int x_root = Find(x);
        int y_root = Find(y);

        if (x_root == y_root)
        {
            return;
        }
        if (rank[x_root] > rank[y_root])
        {
            roots[y_root] = x_root;
        }
        else if (rank[x_root] < rank[y_root])
        {
            roots[x_root] = y_root;
        }
        else
        {
            roots[x_root] = y_root;
            ++rank[y_root];
        }
        --count;
    }
};

class Solution
{
public:
    // UnionFindSet
    // int numIslands(vector<vector<char>>& grid) {
    //     int m = grid.size();
    //     if (m == 0) return 0;
    //     int n = grid[0].size();
    //     if (n == 0) return 0;
    //     int ufs_size = m * n;
    //     UFS ufs(ufs_size);
    //     int water_count = 0;
    //     for (int i = 0; i < m; ++i) {
    //         for (int j = 0; j < n; ++j) {
    //             int pos = i * n + j;
    //             if (grid[i][j] == '0') {
    //                 ++water_count;
    //                 continue;
    //             }

    //             if (j <= n - 2 && grid[i][j + 1] == '1') {
    //                 ufs.Union(i * n + (j + 1), pos);
    //             }
    //             if (i <= m - 2 && grid[i + 1][j] == '1') {
    //                 ufs.Union((i + 1) * n + j, pos);
    //             }
    //         }
    //     }
    //     return ufs.Count() - water_count;
    // }

    // BFS
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;

        int count = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '0')
                {
                    continue;
                }
                ++count;
                grid[i][j] = '0';

                // BFS
                BFS(grid, m, n, i, j);

                // DFS
                // DFS(grid, m, n, i, j);
            }
        }

        return count;
    }

    void BFS(vector<vector<char>> &grid, int m, int n, int i, int j)
    {
        static int dr[4] = {0, 0, -1, 1};
        static int dc[4] = {-1, 1, 0, 0};
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int r = p.first + dr[k];
                int c = p.second + dc[k];
                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                    grid[r][c] = '0';
                    q.push({r, c});
                }
            }
        }
    }

    void DFS(vector<vector<char>> &grid, int m, int n, int i, int j)
    {
        static int dr[4] = {0, 0, -1, 1};
        static int dc[4] = {-1, 1, 0, 0};
        for (int k = 0; k < 4; ++k)
        {
            int r = i + dr[k];
            int c = j + dc[k];
            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1')
            {
                grid[r][c] = '0';
                DFS(grid, m, n, r, c);
            }
        }
    }
};
// @lc code=end
