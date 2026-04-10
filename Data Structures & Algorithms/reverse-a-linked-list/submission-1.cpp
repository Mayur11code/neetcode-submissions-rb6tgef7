class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        
        while (head != nullptr) {
            ListNode* ahead = head->next;
            head->next = prev;
            prev = head;
            head = ahead;
        }
        
        return prev;
    }
};
