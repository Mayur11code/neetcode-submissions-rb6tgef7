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
    void reorderList(ListNode* head) {
       ListNode* slow = head;
       ListNode* fast = head;
    while(fast->next!=nullptr){
        slow=slow->next;
        fast= fast->next;
        if(fast->next!=nullptr){
            fast=fast->next;
        }
    }

    ListNode* prev = nullptr;
    ListNode* ahead = slow;
    ListNode* current = slow;
    while(ahead!=nullptr){
        ahead=ahead->next;
        current->next = prev;
        prev= current;
        current=ahead;
    }
    ListNode* curr = head;
    ListNode* next1 = head->next ;
    ListNode* next2 = fast->next ;
    while(curr!=slow){
        curr->next=fast;
        curr = next1;
        next1 = next1->next;
        if(fast==curr){break;}
        fast->next = curr;
        
        fast=next2;
        next2=next2->next;
    }
        
    }
};
