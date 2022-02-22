#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        dequeue = new int[k];
        head = tail = 0;
        size = 0;
        capacity = k;
    }
    
    bool insertFront(int value) {
        if (isFull())
            return false;
        head = head > 0 ? head - 1 : capacity - 1;
        dequeue[head] = value;
        ++size;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull())
            return false;
        dequeue[tail] = value;
        tail = (tail + 1) % capacity;
        ++size;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty())
            return false;
        head = (head + 1) % capacity;
        --size;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty())
            return false;
        tail = tail > 0 ? tail - 1 : capacity - 1;
        --size;
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : dequeue[head % capacity];
    }
    
    int getRear() {
        return isEmpty() ? -1 : dequeue[tail > 0 ? tail - 1 : capacity - 1];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }

private:
    int *dequeue;
    int size;
    int capacity;
    int head;
    int tail;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
//leetcode submit region end(Prohibit modification and deletion)
