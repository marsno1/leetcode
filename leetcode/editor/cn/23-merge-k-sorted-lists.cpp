#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#define solution_1 true
#define solution_1_pq true // priority_queue
#define solution_1_bh false // BinaryHeap

#if solution_1
// 实现小根堆：定义堆的节点
struct Node {
	int key;
	ListNode *listNode;
	Node(int key, ListNode *listNode): key(key), listNode(listNode) {}
};
#endif

#if solution_1 && solution_1_bh
// 实现小根堆
class BinaryHeap {
public:
	BinaryHeap() {
		heap.push_back(Node(0, nullptr)); // 0位置不用
	}

	bool empty() {
		return heap.size() == 1;
	}

	void push(const Node &node) {
		heap.push_back(node);
		heapifyUp(heap.size() - 1);
	}

	Node top() {
		return heap[1];
	}

	void pop() {
		heap[1] = heap[heap.size() - 1];
		heap.pop_back();
		heapifyDown(1);
	}

private:
	// 向上调整
	void heapifyUp(int p) {
		while (p > 1) { // 如果p有父节点，判断是否需要跟父节点交换
			if (heap[p].key < heap[p/2].key) {
				swap(heap[p], heap[p/2]);
				p = p / 2;
			}
			else
				break;
		}
	}

	// 向下调整
	void heapifyDown(int p) {
		int child = p * 2;
		while (child < heap.size()) { // 如果子节点存在
			int other = child + 1; // 另一个子节点
			if (other < heap.size() && heap[other].key < heap[child].key) {
				child = other;
			}

			if (heap[child].key < heap[p].key) {
				swap(heap[child], heap[p]);
				p = child; // p下移
			}
			else
				break;

			child = p * 2; // child下移
		}
	}

	vector<Node> heap;
};
#endif

#if solution_1 && solution_1_pq
struct compare {
	bool operator() (Node l, Node r) {
		return l.key > r.key;
	}
};
#endif

class Solution {
public:
#if solution_1
    // 解法一：堆
    ListNode* mergeKLists(vector<ListNode*>& lists) {
#if solution_1_pq
        priority_queue<Node, vector<Node>, compare> q; // 小根堆
#elif solution_1_bh
		BinaryHeap q;
#endif
        for (ListNode *ptr : lists) {
            if (ptr)
                q.push(Node(ptr->val, ptr));
        }

        ListNode head;
        ListNode *curr = &head;
        while(!q.empty()) {
            // 取堆顶元素
            curr->next = q.top().listNode;
            q.pop();
            curr = curr->next;

            // 将对应链表的下一个元素入堆
            if (curr->next)
                q.push(Node(curr->next->val, curr->next));
        }
        return head.next;
    }
#endif

#if solution_2
    // 解法二：分治
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0)
            return nullptr;
        if (n == 1)
            return lists.front();

        vector<ListNode*> left_lists(lists.begin(), lists.begin() + n/2);
        vector<ListNode*> right_lists(lists.begin() + n/2, lists.end());
        ListNode* left = mergeKLists(left_lists);
        ListNode* right = mergeKLists(right_lists);

        ListNode head;
        ListNode *curr = &head;
        while(left && right) {
            if (left->val <= right->val) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        if (left)
            curr->next = left;
        else
            curr->next = right;

        return head.next;
    }
#endif
};
//leetcode submit region end(Prohibit modification and deletion)
