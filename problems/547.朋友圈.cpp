/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */

// @lc code=start
// UnionFindSet
class UFS {
    vector<int> roots;
    vector<int> rank;
    int count; // number of distinct roots
public: 
    UFS(int n): roots(n), rank(n), count(n) {
        MakeUFS();
    }

    int Count() {
        return count;
    }

    void MakeUFS() {
        for (int i = 0; i < roots.size(); ++i) {
            roots[i] = i;
        }
    }
    int Find(int x) {
        int root = x;
        while (root != roots[root]) {
            root = roots[root];
        }
        while (x != root) {
            int parent = roots[x];
            roots[x] = root;
            x = parent;
        }
        return root;
    }

    void Union(int x, int y) {
        int x_root = Find(x);
        int y_root = Find(y);

        if (x_root == y_root) {
            return;
        }
        if (rank[x_root] > rank[y_root]) {
            roots[y_root] = x_root;
        } else if (rank[x_root] < rank[y_root]) {
            roots[x_root] = y_root;
        } else {
            roots[x_root] = y_root;
            ++rank[y_root];
        }
        --count;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        if (n == 0) return 0;
        UFS ufs(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (M[i][j] == 0) {
                    continue;
                }
                if (i != j) {
                    ufs.Union(i, j);
                }
            }
        }
        return ufs.Count();
    }
};
// @lc code=end

