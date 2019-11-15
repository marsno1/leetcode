/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
        ListNode *tail = NULL;
        ListNode *p = NULL;
        while (true) {
            if (l1 != NULL && l2 != NULL) {
                if (l1->val <= l2->val) {
                    p = l1;
                    l1 = l1->next;
                } else {
                    p = l2;
                    l2 = l2->next;
                }
            } else if (l1 != NULL) {
                p = l1;
                l1 = l1->next;
            } else if (l2 != NULL) {
                p = l2;
                l2 = l2->next;
            } else {
                break;
            }
            if (head == NULL) {
                head = tail = p;
            } else {
                tail->next = p;
                tail = p;
            }
        }
        return head;
    }
};
// @lc code=end

