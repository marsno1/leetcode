#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> m; // 保存arr2的值和下标的映射
        for (int i = 0; i < arr2.size(); ++i)
            m[arr2[i]] = i;

        sort(arr1.begin(), arr1.end(), [&] (int a, int b){
            int aPos = m.find(a) != m.end() ? m[a] : arr2.size();
            int bPos = m.find(b) != m.end() ? m[b] : arr2.size();
            return aPos < bPos || (aPos == bPos && a < b);
        });
        return arr1;
    }

private:

};
//leetcode submit region end(Prohibit modification and deletion)
