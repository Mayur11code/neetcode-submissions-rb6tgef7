/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    // Helper to find the Kth node from a given start
    ListNode* getK(ListNode* node, int k) {
        while (node != nullptr && k > 1) {
            node = node->next;
            k--;
        }
        return node;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // Edge case safety
        if (k <= 1 || head == nullptr) return head;

        ListNode* target_k = getK(head, k);
        if (target_k == nullptr) return head;

        ListNode* nhead = target_k;
        ListNode* stored_tail = head;
        
     
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        for (int i = 0; i < k; i++) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
     
        while (curr != nullptr) {
            target_k = getK(curr, k);
            if (target_k == nullptr) break; 
            
            ListNode* new_tail = curr;
            ListNode* nxt = curr->next; //  Save the future path
            
            // Hide the old tail in the new tail's next pointer
            new_tail->next = stored_tail;
            stored_tail = new_tail;
            
            // THE PROTECT STEP: Move forward using the lifeboat
            prev = curr;
            curr = nxt; 
            
            // Reverse the remaining K-1 nodes in this group
            for (int i = 1; i < k; i++) {
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            
            //  Connect previous group's tail to this group's head
            // (This automatically resolves the temporary cycle from the previous group)
            stored_tail->next->next = target_k;
        }
        

        // Overwrite the final smuggled pointer to attach any leftover nodes
        // (This breaks the cycle for the very last reversed group)
        stored_tail->next = curr;
        
        return nhead;
    }
};