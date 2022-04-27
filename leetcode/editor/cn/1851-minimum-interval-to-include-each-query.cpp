#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
	// 关键事件思想
	// 批处理所有询问，得到答案后再统一返回。
	// 每个区间看作一个限时任务，在left[i]时产生，在right[i]时消失，任务代价是length[i]；
	// 每个询问看作是一个在queries[i]时发生的“询问”事件：哪个可做的任务代价最小?
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
		int n = intervals.size();
		vector<Event> events;
		for (int i = 0; i < n; ++i) {
			const auto & interval = intervals[i];
			int len = interval[1] - interval[0] + 1;
			events.push_back({interval[0], len, 1});
			events.push_back({interval[1], len, -1});
		}
		for (int i = 0; i < queries.size(); ++i) {
			events.push_back({queries[i], i, 0});
		}
		// 将事件排序
		sort(events.begin(), events.end(), [](const Event & a, const Event & b) {
			return a.pos < b.pos || (a.pos == b.pos && a.type > b.type);
		});
		// 处理事件
		map<int, int> m; // 有序映射(也可以用小根堆)：key是区间长度，value是区间个数
		vector<int> ans(queries.size());
		for (int i = 0; i < events.size(); ++i) {
			const auto & event = events[i];
			if (event.type == 1) {
				// 遇到区间左端点时，说明这个区间覆盖开始了。
				m[event.len]++;
			} else if (event.type == -1) {
				// 遇到区间右端点时，说明这个区间覆盖应该结束，那么将它对应的左端点事件删除。
				m[event.len]--;
				if (m[event.len] == 0) m.erase(event.len);
			} else {
				// 询问事件：当前集合中保存的就是正处于覆盖中的区间，所以取集合中的最小区间(即最小长度)
				ans[event.len] = m.empty() ? -1 : m.begin()->first;
			}
		}
		return ans;
    }

private:
	struct Event {
		int pos;
		int len; // 对于区间事件表示区间长度，对于询问事件表示原始下标
		int type; // 事件类型：1表示区间左端点，-1表示区间右端点，0表示询问事件
	};
};
//leetcode submit region end(Prohibit modification and deletion)
