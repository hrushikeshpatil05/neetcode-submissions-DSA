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
    int findLengthOfList(ListNode* head) {

        int length = 0;

        ListNode* temp = head;
        while(temp) {
            length++;
            temp = temp->next;
        }
        return length;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = findLengthOfList(head);
        if(length == n) {
            return head->next;
        }

        int nodeToRemove = length - n;

        ListNode* temp = head;
        ListNode* prev = temp;

        while(temp) {
            nodeToRemove--;
            if(nodeToRemove == 0) {
                cout<<"here"<<temp->val<<endl;
                ListNode* nextNode = temp->next ? temp->next : nullptr;
                cout<<nextNode->val<<endl;
                temp->next = nextNode->next;
                // return head;
            }
            temp = temp->next;
        }
        return prev;
    }
};
