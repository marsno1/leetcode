/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
        int m, n;
        m = listLength(l1);
        n = listLength(l2);
        ListNode *head = NULL;
        pair<ListNode*, int> p = addTwoNumber(l1, l2, m, n);
        if (p.second > 0) {
            head = new ListNode(p.second);
            head->next = p.first;
        } else {
            head = p.first;
        }
        return head;
    }

    pair<ListNode*, int> addTwoNumber(ListNode* l1, ListNode* l2, int m, int n) {
        if (l1 == NULL && l2 == NULL) {
            return {NULL, 0};
        }

        pair<ListNode*, int> p;
        ListNode *curr = NULL;
        int sum;
        if (m == n) {
            p = addTwoNumber(l1->next, l2->next, m - 1, n - 1);
            sum = l1->val + l2->val + p.second;
        } else if (m > n) {
            p = addTwoNumber(l1->next, l2, m - 1, n);
            sum = l1->val + p.second;
        } else {
            p = addTwoNumber(l1, l2->next, m, n - 1);
            sum = l2->val + p.second;
        }
        curr = new ListNode(sum % 10);
        curr->next = p.first;
        return {curr, sum / 10};
    }

    int listLength(ListNode* l) {
        int count = 0;
        while (l) {
            ++count;
            l = l->next;
        }
        return count;
    }
};
// @lc code=end

