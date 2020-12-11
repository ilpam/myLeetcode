/*
* 此题可以用递归解法还有迭代解法，不过递归解法比较不容易出错
*
*/

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
        if (!head) return nullptr;
        ListNode *a = head, *b = head;
        int count = 0;
        while (count < k && b) {
            b = b->next;
            count++;
        }
        //b = b->next;

        if (count == k) {
            // b maybe null
            ListNode *frontK = reverseList(a, b);
            ListNode *remain = reverseKGroup(b, k);
            a->next = remain;
            return frontK;
        } else {
            return head;
        }
    }

    // reverse [a,b)
    ListNode* reverseList(ListNode *a, ListNode *b) {
        ListNode *curr = a, *next, *prev = NULL;
        while (curr != b) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};