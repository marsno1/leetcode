/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */

// @lc code=start
class LRUCache {
private:
    typedef list<int> L; // key
    typedef L::iterator LI; // 根据list的迭代器，既可以访问list中的元素，也可以取出key进而访问map
    typedef pair<int, LI> P; // value and list iterator 
    
    unordered_map<int, P> m;
    L l;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) {
            return -1;
        }
        P p = it->second;
        int value = p.first;
        LI li = p.second;
        touch(li);
        it->second.second = l.begin();
        return value;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) {
            P p = it->second;
            LI li = p.second;
            touch(li);
            m[key] = {value, l.begin()};
            return;
        }
        // 删除链表中最后一个元素
        if (m.size() >= capacity) {
            m.erase(l.back());
            l.pop_back();
        }
        // 插入新元素
        l.push_front(key);
        m[key] = {value, l.begin()};
    }

    void touch(LI it) {
        int key = *it;
        l.erase(it);
        l.push_front(key);
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

