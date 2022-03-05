#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const string & str : strs) {
            string copy = str;
            sort(copy.begin(), copy.end());
            groups[copy].push_back(str);
        }

        vector<vector<string>> ans;
        for (const auto & group : groups) {
            ans.emplace_back(std::move(group.second));
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
