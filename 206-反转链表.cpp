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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *backward = head, *curr = head->next, *forward = curr->next;
        do {
            if (backward == head) {
                backward->next = NULL;
            }
            curr->next = backward;
            if (forward) {
                backward = curr;
                curr = forward;
                forward = forward->next;
            }
        } while (forward);
        curr->next = backward;
        return curr;
    }
};

// solution 2, more clear
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head, *save, *prev = NULL;
        while (curr) {
            save = curr->next;
            curr->next = prev;
            prev = curr;
            curr = save;
        }
        return prev;
    }
};