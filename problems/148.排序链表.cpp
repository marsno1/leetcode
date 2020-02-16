/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        // fast指针必须从第二个节点开始，这样正好是slow长度的两倍
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = NULL;

        return mergeList(sortList(head), sortList(fast));
    }

    ListNode* mergeList(ListNode* p, ListNode* q) {
        ListNode head(0);
        ListNode *curr = &head;
        while (p != NULL & q != NULL) {
            if (p->val < q->val) {
                curr->next = p;
                p = p->next;
            } else {
                curr->next = q;
                q = q->next;
            }
            curr = curr->next;
        }
        if (p == NULL) {
            curr->next = q; 
        } else {
            curr->next = p;
        }
        return head.next;
    }
};
// @lc code=end

