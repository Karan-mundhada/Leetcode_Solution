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
        int carry = 0;
        ListNode* prev = l1;
        ListNode* head = l1;
        while(l1 != NULL && l2 != NULL)
        {
            int t = l1->val + l2->val + carry;
            carry = t / 10;
            l1->val = t % 10;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != NULL)
        {
            int t = l1->val + carry;
            carry = t / 10;
            l1->val = t % 10;
            prev = l1;
            l1 = l1->next;
        }

        while(l2 != NULL)
        {
            int t = l2->val + carry;
            carry = t / 10;
            prev->next = new ListNode(t % 10);
            prev = prev->next;
            l2 = l2->next;
        }

        if(carry != 0)
            prev->next = new ListNode(1);

        return head;
    }
};