/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *curr = head;
        int carry = 0;
        while (true) {
            if (l1 == NULL && l2 == NULL) {
                if (carry > 0) {
                    curr->next = new ListNode(carry);
                }
                break;
            }
            
            curr->next = new ListNode(carry);
            curr = curr->next;
            if (l1 != NULL) {
                curr->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                curr->val += l2->val;
                l2 = l2->next;
            }
            if (curr->val >= 10) {
                carry = curr->val / 10;
                curr->val %= 10;
            } else {
                carry = 0;
            }
        }
        return head->next;
    }
};
// @lc code=end

