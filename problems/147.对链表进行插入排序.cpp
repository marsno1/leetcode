/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *p = head->next;
        ListNode *pprev = head;
        while (p != NULL) {
            if (pprev->val > p->val) {
                // 如果当前元素小于前一个元素，则需要把当前元素向前插入
                ListNode *q = head;
                ListNode *qprev = NULL;
                while (q != p) {
                    if (q->val < p->val) {
                        qprev = q;
                        q = q->next;
                    } else {
                        // 先修复p的前向节点的next指针
                        pprev->next = p->next;
                        if (qprev == NULL) {
                            head = p;
                        } else {
                            qprev->next = p;
                        }
                        p->next = q;
                        // p指向下一个元素
                        p = pprev->next;
                        break;
                    }
                }
            } else {
                pprev = p;
                p = p->next;
            }
        }
        return head;
    }
};
// @lc code=end

