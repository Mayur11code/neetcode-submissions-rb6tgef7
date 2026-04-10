class Solution {
public:
    // YOUR EXACT FUNCTION (with kptr initialized to fix the k=1 crash)
    ListNode* getK(ListNode* dummy, int k) {
        ListNode* kptr = dummy; 
        if (dummy == nullptr) return nullptr;
        
        for (int i = 1; i < k; i++) {
            if (dummy->next) {
                kptr = dummy->next;
                dummy = dummy->next;
            } else {
                return nullptr; // Reached end before k nodes
            }
        }
        return kptr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // 1. THE SETUP
        ListNode* dummy = new ListNode(0, head); // Create a true dummy to act as the first "parent"
        ListNode* prevTail = dummy;              // This is the "parent node we stored"
        ListNode* curr = head;

        while (curr != nullptr) {
            // 2. THE PROBE (Using your function)
            ListNode* kpointer = getK(curr, k);
            
            if (kpointer == nullptr) {
                break; // If fewer than k nodes left, we are done.
            }

            // Save the start of the NEXT group so we don't lose the rest of the list
            ListNode* nextGroupStart = kpointer->next;

            // 3. THE REVERSAL (Your exact 3-pointer logic, isolated!)
            ListNode* prev = nextGroupStart; // Point the first reversed node to the future
            ListNode* tempCurr = curr;
            
            while (tempCurr != nextGroupStart) {
                ListNode* nxt = tempCurr->next;
                tempCurr->next = prev;     // curr->next = prev;
                prev = tempCurr;           // prev = curr;
                tempCurr = nxt;            // curr = nxt;
            }

            // 4. THE REWIRING 
            // curr is now the tail of our reversed group. 
            // kpointer is now the head.
            ListNode* newTailForThisGroup = curr; 
            
            prevTail->next = kpointer;     // Connect parent to the new head
            prevTail = newTailForThisGroup;// Update parent anchor for the next round
            
            // 5. THE SHIFT
            curr = nextGroupStart;         // Move to the next group
        }

        return dummy->next;
    }
};