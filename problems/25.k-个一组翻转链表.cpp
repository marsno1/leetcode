/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) 
            return head;
            
        ListNode sentinel(0, head);
        ListNode* prev = &sentinel;
        while (head) {
            // 找出需要处理的一个组
            ListNode* tail = getTail(head, k);
            if (tail == nullptr)
                break;

            ListNode* next_head = tail->next;

            // 组内反转，处理左闭右开区间[head, next_head)
            reverse(head, next_head);

            // 组之间连接
            prev->next = tail;
            head->next = next_head;

            // 移动到下一组
            prev = head;
            head = next_head;
        }
        return sentinel.next;
    }

    ListNode* getTail(ListNode* head, int k) {
        while (head) {
            k--;
            if (k == 0)
                return head;
            head = head->next;
        }
        return head; // head is null: 不够k个节点
    }

    void reverse(ListNode* head, ListNode *next_head) {
        // 第一个节点不需要处理，所以curr初始时指向第二个节点
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr != next_head) {
            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }
    }
};
// @lc code=end
