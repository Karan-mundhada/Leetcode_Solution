/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        // if(head == NULL || head->next == NULL)
        //     return head;

        Node* dum = head;
        while(dum != NULL)
        {
            Node* nex = dum->next;
            if(dum->child != NULL)
            {
                Node* temp = dum->child;
                dum->child = NULL;
                temp = flatten(temp);
                dum->next = temp;
                temp->prev = dum;
                while(temp->next != NULL)
                    temp = temp->next;

                temp->next = nex;
                if(nex != NULL)
                    nex->prev = temp;
            }

            dum = nex;
        }

        return head;

    }
};