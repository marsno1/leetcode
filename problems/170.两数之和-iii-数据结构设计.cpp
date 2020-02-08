// 也可以用multi_set<int>，利用有序性和双指针法
class TwoSum {
private:
    unordered_map<int, int> m;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        ++m[number];
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto p : m) {
            int x = p.first;
            int y = value - x;
            if (m.find(y) != m.end()) {
                if (x != y || (x == y && p.second > 1))
                    return true;
            }
        }
        return false;
    }
};