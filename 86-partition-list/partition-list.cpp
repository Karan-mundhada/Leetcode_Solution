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
    ListNode* partition(ListNode* head, int x) {
        ListNode* l1 = new ListNode(0); // Placeholder for < x
        ListNode* l2 = new ListNode(0); // Placeholder for >= x
        ListNode* head1 = l1; // Pointer to track < x list
        ListNode* head2 = l2; // Pointer to track >= x list
        
        while (head != NULL) {
            if (head->val < x) {
                l1->next = head; // Link the current node
                l1 = l1->next;   // Move to the next node
            } else {
                l2->next = head; // Link the current node
                l2 = l2->next;   // Move to the next node
            }
            head = head->next; // Move to the next node in the original list
        }
        
        l2->next = NULL;    // End the >= x list
        l1->next = head2->next; // Connect < x list to >= x list
        
        return head1->next; // Return the head of the < x list
    }
};