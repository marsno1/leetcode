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
class Solution {
    struct Comp {
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comp> q;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) {
                q.push(lists[i]);
            }
        }

        ListNode head(0);
        ListNode *curr = &head;
        while (!q.empty()) {
            ListNode *t = q.top();
            q.pop();
            curr->next = t;
            curr = curr->next;
            if (t->next) {
                q.push(t->next);
            }
        }
        return head.next;
    }
};
// @lc code=end

