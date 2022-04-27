#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 解法一：单调队列-递减队列
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        vector<int> ans;
//        deque<int> q;
//        for (int i = 0; i < nums.size(); ++i) {
//            // 队列头部元素过期了
//            if (!q.empty() && q.front() <= i - k) {
//                q.pop_front();
//            }
//            // 维护队列的单调性
//            while (!q.empty() && nums[i] >= nums[q.back()]) {
//                q.pop_back();
//            }
//            // 新元素入队列
//            q.push_back(i);
//            // 计算答案
//            if (i >= k - 1)
//                ans.push_back(nums[q.front()]);
//        }
//        return ans;
//    }

    // 解法二：堆+懒惰删除法
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        // 使用大根堆保存元素的值和下标（less对应大根堆，greater对应小根堆）
        // pair数据类型的比较逻辑是依次比较first和second，把数值作为first可以保证是大根堆
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < nums.size(); ++i) {
            q.push({nums[i], i});
            if (i >= k - 1) { // 窗口满了，需要计算答案
                // 弹出堆顶且过期的元素
                // 注意：堆中可能保留过期的元素不在堆顶，但这并不妨碍计算答案
                while (!q.empty() && q.top().second <= i - k) {
                    q.pop();
                }
                ans.push_back(q.top().first);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
