#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class LRUCache {
    // 两种设计方案(要求list取尾节点时要能够得到key，用于从map中淘汰元素):
    // 1.
    // map元素:  {key => pair{value, list_iterator}}
    // list元素: {key}
    // 2.
    // map元素:  {key => list_iterator}
    // list元素: {pair{key, value}}
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        unordered_map<int, list<element>::iterator>::iterator it = m.find(key);
        if (it != m.end()) {
            int value = (it->second)->second;
            // 从链表中删除旧节点，并插入新节点
            l.erase(it->second);
            l.insert(l.begin(), {key, value});
            // 更新map指向链表的新节点
            m[key] = l.begin();
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        unordered_map<int, list<element>::iterator>::iterator it = m.find(key);
        if (it != m.end()) { // 更新存在的元素
            // 从链表中删除旧节点
            l.erase(it->second);
        } else { // 插入新元素
            if (m.size() >= cap) {
                // 从链表中删除尾节点
                m.erase(l.back().first);
                l.pop_back();
            }
        }
        l.insert(l.begin(), {key, value});
        // 向map中插入元素，指向链表的新节点
        m[key] = l.begin();
    }

private:
    using element = pair<int, int>;
    list<element> l;
    unordered_map<int, list<element>::iterator> m;
    int cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)
