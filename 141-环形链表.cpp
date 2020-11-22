
/**
 *
 * 方法一：用集合记录已访问结点
 * 方法二：快慢指针 
 * 
 * 
 */

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
        if (head == NULL || head->next == NULL) {
            return false;
        }
        ListNode *fast = head->next, *slow = head;
        while (fast != slow) {
            if ((fast->next != NULL) && (fast->next->next) != NULL) {
                fast = fast->next->next;
                slow = slow->next;
            } else {
                return false;
            }
        }
        return true;
    }
};