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
    ListNode* sortList(ListNode* head) {
        priority_queue<int, vector<int>, greater<int>> pq;
        ListNode *real = head;
        while(head != NULL)
        {
            pq.push(head->val);
            head = head->next;
        }
        head = real;
        while(head != NULL)
        {
            head->val = pq.top();
            pq.pop();
            head = head->next;
        }

        return real;
    }
};