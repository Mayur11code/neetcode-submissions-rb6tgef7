class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // STEP 1: Find the middle
        // Master trick: Start fast at head->next so slow lands exactly 
        // on the tail of the first half for both even and odd length lists.
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // STEP 2: Reverse the second half
        ListNode* second = slow->next;
        slow->next = nullptr; // CRITICAL: Sever the first half from the second!
        ListNode* prev = nullptr;
        
        while (second != nullptr) {
            ListNode* tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }

        // STEP 3: Merge the two halves
        ListNode* first = head;
        second = prev; // 'prev' is the new head of the reversed second half
        
        while (second != nullptr) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            
            first->next = second;
            second->next = tmp1;
            
            first = tmp1;
            second = tmp2;
        }
    }
};