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
        int carry=0;
        ListNode* curr = new ListNode(0);
        ListNode* prev = new ListNode(0,curr);
    
        ListNode* rhead = curr;

        ListNode* head1 = l1;
        ListNode* head2 = l2;
        while(head1 || head2 || carry==1){
            int op1= head1 ? (head1->val ? head1->val : 0) : 0; 
            int op2= head2 ? (head2->val ? head2->val : 0) : 0; 
           
            int result = op1+op2+carry;
            
            if(result>=10){
                carry =1;
                result = result -10;
            }
            else { carry = 0;}
            curr->val= result;
            prev=curr;
            ListNode* nextnode = new ListNode();
            curr=nextnode;
            prev->next = curr;
            head1= head1 ? (head1->next ? head1->next : nullptr) : nullptr;
            head2= head2 ? (head2->next ? head2->next : nullptr) : nullptr;
            
            

        }
        prev->next = nullptr;

        return rhead;
        
    }
};
