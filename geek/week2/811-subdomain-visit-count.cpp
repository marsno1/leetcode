#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> domain_to_count;
        for (const string & cpdomain : cpdomains) {
            vector<string> domains;
            // 解析count值和所有子域名
            int count = parseCpDomain(cpdomain, domains);
            for (const string & domain : domains) {
                domain_to_count[domain] += count;
            }
        }

        // 整理结果
        vector<string> ans;
        for (const auto & it : domain_to_count) {
            ans.push_back(to_string(it.second) + " " + it.first);
        }
        return ans;
    }

    int parseCpDomain(const string & cpdomain, vector<string> & domains) {
        // 解析count值
        int index = cpdomain.find(' ');
        int count = atoi(cpdomain.substr(0, index).c_str());

        // 保存完整域名
        string full_domain = cpdomain.substr(index + 1);
        domains.push_back(full_domain);

        // 解析子域名
        index = 0;
        while (true) {
            index = full_domain.find( '.', index);
            if (index == -1)
                break;
            ++index;
            domains.push_back(full_domain.substr(index));
        }
        return count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
