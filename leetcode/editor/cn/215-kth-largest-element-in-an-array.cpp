#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
struct my_greater {
    bool operator() (int l, int r) {
        return l > r;
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 用小顶堆把更小的元素排除
        // 小顶堆的输出顺序是升序，所以用greater
        priority_queue<int, vector<int>, my_greater> q;
        for (int x : nums) {
            if (q.size() < k) {
                q.push(x);
            } else {
                if (x > q.top()) {
                    q.pop();
                    q.push(x);
                }
            }
        }
        return q.top();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
