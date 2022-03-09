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
struct compare {
    bool operator() (ListNode *l, ListNode *r) {
        return l->val > r->val;
    }
};

class Solution {
public:
    // 解法一：堆
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        priority_queue<ListNode*, vector<ListNode*>, compare> q;
//
//        for (ListNode *ptr : lists) {
//            if (ptr)
//                q.push(ptr);
//        }
//
//        ListNode head;
//        ListNode *curr = &head;
//        while(!q.empty()) {
//            // 取堆顶元素
//            curr->next = q.top();
//            q.pop();
//            curr = curr->next;
//
//            // 将对应链表的下一个元素入堆
//            if (curr->next)
//                q.push(curr->next);
//        }
//        return head.next;
//    }

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
};
//leetcode submit region end(Prohibit modification and deletion)
