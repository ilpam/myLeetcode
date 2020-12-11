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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        ListNode *left = head, *right;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast) {
            slow = slow->next;
        }
        right = reverse(slow);
        while (right) {
            if (right->val != left->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }

    ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr, *curr = head, *next;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};