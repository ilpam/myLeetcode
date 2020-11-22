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
        ListNode *result = nullptr, *tail, *tmp, *left;
        unsigned int tmp_sum = 0;
        unsigned int extra = 0;

        while (l1 && l2) {
            if ((tmp_sum = l1->val + l2->val + extra) >= 10) {
                tmp_sum = tmp_sum % 10;
                extra = 1;
            } else {
                extra = 0;
            }

            tmp = new ListNode(tmp_sum);
            if (result == nullptr) {
                result = tail = tmp;
            } else {
                tail->next = tmp;
                tail = tmp;
            }
                
            l1 = l1->next;
            l2 = l2->next;
        }

        left = (!l1) ? l2 : l1;
        if (extra == 1) {
            while (left) {
                if ((tmp_sum = left->val + extra) >= 10) {
                    tmp_sum = tmp_sum % 10;
                    extra = 1;
                } else {
                    extra = 0;
                }

                tmp = new ListNode(tmp_sum);
                if (result == nullptr) {
                    result = tail = tmp;
                } else {
                    tail->next = tmp;
                    tail = tmp;
                }
                left = left->next;
            }

        } else {

            while (left) {
                tmp = new ListNode(left->val);
                tail->next = tmp;
                tail = tmp;
                left = left->next;
            }
        }

        if (extra) {
            tail->next = new ListNode(1);
            tail->next->next = nullptr;
        }

        return result;
    }
};