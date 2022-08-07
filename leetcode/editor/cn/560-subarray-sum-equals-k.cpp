#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int> prefix_sum(n);
		prefix_sum[0] = nums[0];
		for (int i = 1; i < n; ++i)
			prefix_sum[i] = prefix_sum[i - 1] + nums[i];

		int ans = 0;
		unordered_map<int, int> m; // 前缀和的数值与个数的映射
		m[0] = 1; // 存在1个空数组，它的前缀和为0
		for (int i = 0; i < n; ++i)
		{
			int q = prefix_sum[i];
			int p = q - k; // 判断另一个前缀和是否在map里
			if (m.find(p) != m.end())
				ans += m[p]; // 累加已经存在的p值数量
			m[q]++; // 把当前值放入map里
		}
		return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
