#include "include/headers.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;

        ListNode sentinal;
        sentinal.next = head;

        // 判断是否有环
        ListNode *fast = &sentinal;
        ListNode *slow = &sentinal;
        while (!(fast == nullptr || fast->next == nullptr || slow == nullptr)) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
                break;
        }
        if (fast != slow)
            return nullptr;

        // 计算环中的节点数量
        int n = 1;
        for (fast = fast->next; fast != slow; fast = fast->next, ++n);

        // 找到倒数第n个节点，即环的入口节点
        // 1.slow走到第1个节点，fast走到第n个节点
        slow = sentinal.next;
        fast = &sentinal;
        for (int i = 0; i < n; ++i)
            fast = fast->next;

        // 2.fast和slow同步走，当fast走到链表尾节点时，slow就走到了倒数第n个节点
        while (fast->next != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
