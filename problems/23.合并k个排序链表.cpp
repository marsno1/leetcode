/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
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
struct Comp {
    bool operator() (ListNode* l, ListNode* r) {
        return l->val > r->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comp> pq;
        for (auto p: lists) {
            if (p) {
                pq.push(p);
            }
        }

        ListNode *head = NULL, *curr = NULL;
        while(!pq.empty()) {
            ListNode *node = pq.top();
            pq.pop();
            if (head == NULL) {
                head = curr = node;
            } else {
                curr->next = node;
                curr = node;
            }
            if (node->next != NULL) {
                pq.push(node->next);
            }
        }
        return head;
    }
};
// @lc code=end

