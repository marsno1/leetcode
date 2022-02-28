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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode sentry(0, head);
        ListNode *prev_head = &sentry;

        while (true) {
            ListNode *tail = getTail(head, k);
            if (!tail) {
                break;
            }

            // 保存下一组的头节点，用于前移当前组
            ListNode *next_head = tail->next;
            // 组内反转
            reverse(head, next_head);

            // 组间连接
            prev_head->next = tail;
            head->next = next_head; // 默认下一组不需要翻转，那么连接到下一组的头节点

            // 移动到下一组
            prev_head = head;
            head =  next_head;
        }

        return sentry.next;
    }

    ListNode* getTail(ListNode* head, int k) {
        ListNode *tail = head;
        for (int i = 0; i < k - 1 && tail; ++i) {
            tail = tail->next;
        }
        return tail;
    }

    ListNode* reverse(ListNode* head, ListNode* next_head) {
        if (!head) return nullptr;

        ListNode *prev = nullptr;
        while (head != next_head) {
            // 保存下一个节点
            ListNode *next = head->next;

            // 修改当前节点
            head->next = prev;

            // 前移当前节点
            prev = head;
            head = next;
        }
        return prev;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
