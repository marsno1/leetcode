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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        int sum = 0;
        while (true) {
            if (!l1 && !l2) {
                if (sum > 0)
                    curr->next = new ListNode(sum);
                break;
            }
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            int val = (sum >= 10 ? sum - 10 : sum);
            curr->next = new ListNode(val);
            curr = curr->next;
            sum = sum >= 10 ? 1 : 0;
        }
        return head->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
