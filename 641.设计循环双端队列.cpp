/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 */

// @lc code=start
class MyCircularDeque {
    int *deque;
    int front; // points the first element
    int rear;  // points the position after the last element
    int size;
    int capacity;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        deque = new int[k];
        front = rear = 0;
        size = 0;
        capacity = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (size == capacity) {
            return false;
        }
        front = (front + capacity - 1) % capacity;
        deque[front] = value;
        size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (size == capacity) {
            return false;
        }
        deque[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (size == 0) {
            return false;
        }
        front = (front + 1) % capacity;
        size--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (size == 0) {
            return false;
        }
        rear = (rear + capacity - 1) % capacity;
        size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (size == 0) {
            return -1;
        }
        return deque[front];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (size == 0) {
            return -1;
        }
        return deque[(rear + capacity - 1) % capacity];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == capacity;
    }
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
// @lc code=end

