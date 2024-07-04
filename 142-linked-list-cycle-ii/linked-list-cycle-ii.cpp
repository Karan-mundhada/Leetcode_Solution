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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return NULL;

        ListNode* slo = head;
        ListNode* fas = head;

        while(fas != NULL && fas->next != NULL)
        {
            slo = slo->next;
            fas = fas->next->next;

            if(slo == fas)
            {
                slo = head;

                while(slo != fas)
                {
                    slo = slo->next;
                    fas = fas->next;
                }

                return slo;
            }
        }

        return NULL;
    }
};