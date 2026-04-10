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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     ListNode* tail=head;

     for(int i=1;i<n;i++){
        tail=tail->next;
     }
    if(tail->next == nullptr){
        return head->next ;
    }
     ListNode* prev=head;

     while(tail->next && tail->next->next!=nullptr){
        prev=prev->next;
        tail=tail->next;
     }



    ListNode* temp = prev->next;
    prev->next = temp->next;
    return head;


    }
};
