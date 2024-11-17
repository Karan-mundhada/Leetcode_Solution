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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;
        //DRY RUN IT FOR BETTER UNDERSTANDING
        while(head != NULL)
        {
            if(head->next != NULL && head->next->val == head->val)
            {
                while(head->next != NULL && head->next->val == head->val)
                {
                    head = head->next;
                    // cout<<head->val<<endl;
                }

                prev->next = head->next;
                // cout<<"here"<<endl;
            }
            else
                prev = prev->next;

            head = head->next;
        }

        return dummy->next;
    }
};