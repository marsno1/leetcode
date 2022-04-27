#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
	// 批处理+差分思想
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		int n = buildings.size();
		vector<Event> events;
		// 拆分成两个事件
		for (int i = 0; i < n; ++i) {
			const auto & building = buildings[i];
			events.push_back({building[0], building[2], 1, i});
			events.push_back({building[1], building[2], 0, i});
		}
		// 排序事件
		sort(events.begin(), events.end(), [](const Event & a, const Event & b) {
			return a.pos < b.pos;
		});
		// 用大根堆记录左端点事件，遇到右端点时删除堆中的左端点事件
		priority_queue<pair<int, int>> q; // 存储height和index
		removed.resize(n, false);
		vector<vector<int>> ans;
		for (int i = 0; i < events.size(); ++i) {
			const auto & event = events[i];
			if (event.type == 1) { // 左端点事件
				q.push({event.height, event.index});
			} else { // 右端点事件
				removed[event.index] = true;
			}
			// 如果当前的点与后面的点重合，则直到所有重合的点都处理完毕
			if (i < events.size() - 1 && event.pos == events[i + 1].pos)
				continue;

			// 取堆中最高的点，更新答案
			while (!q.empty() && removed[q.top().second]) { // 懒惰删除法
				q.pop();
			}
			int height = q.empty() ? 0 : q.top().first;
			int pos = event.pos;
			if (ans.empty() || height != ans[ans.size() - 1][1]) // 不输出重复高度
				ans.push_back({pos, height});
		}
		return ans;
    }

private:
	// 每个建筑物的左、右两个端点各对应一个事件
	struct Event {
		int pos; // 横坐标
		int height; // 高度
		int type; // 事件类型：1表示左端点，0表示右端点
		int index; // 建筑物下标
	};
	vector<bool> removed; // 用于大根堆的懒惰删除

};
//leetcode submit region end(Prohibit modification and deletion)
