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
    bool hasCycle(ListNode *head) {
        ListNode sentinal;
        sentinal.next = head;
        ListNode *fast = &sentinal;
        ListNode *slow = &sentinal;
        while (!(fast == nullptr || fast->next == nullptr || slow == nullptr)) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
                return true;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
