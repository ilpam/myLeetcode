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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *prev, *curr = head, *next;
        ListNode *pLeft = nullptr;
        ListNode *end;

        // make curr point to start of reverse List, pLeft point to before of start
        int i = 1;
        while (i != m) {
            pLeft = curr;
            curr = curr->next;
            ++i;
        }
        end = curr;  // save end of reverse List
        prev = nullptr;  // reset prev

        while (i != n+1) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            ++i;
        }

        // check if list length more than 1, and remember to change head
        if (pLeft) {
            pLeft->next = prev;
        } else {
            head = prev;
        }
            
        end->next = curr;
        return head;
    }
};


//此题也有迭代解法，但是你先实现反转到n为止