#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        ns.push(val);
        if (ds.empty() || val <= ds.top())
            ds.push(val);
    }
    
    void pop() {
        if (ns.top() == ds.top())
            ds.pop();
        ns.pop();
    }
    
    int top() {
        return ns.top();
    }
    
    int getMin() {
        return ds.top();
    }

private:
    // normal stack
    stack<int> ns;
    // descreasing stack: 当遇到更小的新元素(或与栈顶元素相等)时才入栈
    stack<int> ds;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
//leetcode submit region end(Prohibit modification and deletion)
