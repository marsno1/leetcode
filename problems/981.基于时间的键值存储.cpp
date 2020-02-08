/*
 * @lc app=leetcode.cn id=981 lang=cpp
 *
 * [981] 基于时间的键值存储
 */

// @lc code=start
class TimeMap {
    unordered_map<string, vector<pair<string,int>>> m;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value, timestamp});
    }
    
    // nums[i]==target || (nums[i] < target && (i==n-1 || nums[i+1] > target))
    string get(string key, int timestamp) {
        auto it = m.find(key);
        if(it == m.end()) {
            return "";
        }

        vector<pair<string,int>>& v = it->second;
        int n = v.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (v[mid].second == timestamp ||
                (v[mid].second < timestamp && (mid == n - 1 || v[mid + 1].second > timestamp))) {
                    return v[mid].first;
            } else if (v[mid].second > timestamp) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

