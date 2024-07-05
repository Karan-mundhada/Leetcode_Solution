/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;

        unordered_map<Node*, Node*> mp;

        Node* newhead = new Node(head->val);
        mp[head] = newhead;
        Node* temp1 = head;
        Node* temp2 = newhead;
        while(temp1->next != NULL)
        {
            temp1 = temp1->next;
            temp2->next = new Node(temp1->val);
            temp2 = temp2->next;
            mp[temp1] = temp2;
        } 

        temp1 = head;
        temp2 = newhead;
        while(temp1 != NULL)
        {
            if(temp1->random != NULL)
            {
                temp2->random = mp[temp1->random];
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return newhead;
    }
};