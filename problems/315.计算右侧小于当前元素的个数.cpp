/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
struct Node {
    Node(int l, int u) {
        lower = l;
        upper = u;
        // [lower, mid], [mid+1, upper]
        mid = lower + (upper - lower) / 2;
        count = 0;
        left = right = NULL;
    }
    int lower;
    int upper;
    int mid;
    int count;
    Node *left;
    Node *right;
};

class SegmentTree {
    Node *root;
public: 
    SegmentTree(int lower, int upper) {
        root = new Node(lower, upper);
    }

    void Add(int x) {
        int mid;
        Node *curr = root;
        while (curr->lower <= curr->upper) {
            ++curr->count;
            if (curr->lower == curr->upper) {
                break;
            }
            mid = curr->mid;
            if (x <= mid) {
                if (curr->left == NULL) {
                    curr->left = new Node(curr->lower, mid);
                }
                curr = curr->left;
            } else {
                if (curr->right == NULL) {
                    curr->right = new Node(mid + 1, curr->upper);
                }
                curr = curr->right;
            }
        }
    }

    int FindInternal(Node *curr, int lower, int upper) {
        if (curr == NULL || lower > upper) {
            return 0;
        }
        if (lower == curr->lower && upper == curr->upper) {
            return curr->count;
        }
        if (upper <= curr->mid) {
            return FindInternal(curr->left, lower, upper);
        } else if (lower > curr->mid) {
            return FindInternal(curr->right, lower, upper);
        } else {
            int left_count = FindInternal(curr->left, lower, curr->mid);
            int right_count = FindInternal(curr->right, curr->mid + 1, upper);
            return left_count + right_count;
        }
    }

    int Find(int lower, int upper) {
        return FindInternal(root, lower, upper);
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n);
        if (n == 0) return counts;
        int lower = INT_MAX, upper = INT_MIN;
        for (int i = 0; i < n; ++i) {
            lower = min(lower, nums[i]);
            upper = max(upper, nums[i]);
        }

        SegmentTree st(lower, upper);
        for (int i = n - 1; i >= 0; --i) {
            st.Add(nums[i]);
            counts[i] = st.Find(lower, nums[i] - 1);
        }

        return counts;
    }
};
// @lc code=end

