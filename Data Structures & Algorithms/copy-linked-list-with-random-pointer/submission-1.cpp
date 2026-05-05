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
        Node* curr = head;

        while(curr) {
            Node* temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = curr->next->next;
        }

        curr = head;

        while(curr) {
            if(curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        curr = head;

        Node* res = new Node(-1);
        Node* copy = res;

        while(curr) {
            copy->next = curr->next;
            copy = copy->next;

            curr->next = curr->next->next;
            curr = curr->next;
        }

        return res->next;
    }
};
