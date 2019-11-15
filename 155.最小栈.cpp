/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
    stack<int> ns; // normal stack
    stack<int> ds; // descreasing stack
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        ns.push(x);
        if (ds.empty() || x <= ds.top()) {
            ds.push(x);
        }
    }
    
    void pop() {
        if (ns.empty()) return;
        if (ns.top() == ds.top()) {
            ds.pop();
        }
        ns.pop();
    }
    
    int top() {
        return ns.top();
    }
    
    int getMin() {
        return ds.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

