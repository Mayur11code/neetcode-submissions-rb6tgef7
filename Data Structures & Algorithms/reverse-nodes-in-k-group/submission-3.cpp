class Solution {
public:
    ListNode* nhead;
    
    ListNode* getK(ListNode* dummy,int k){
        ListNode* kptr = dummy; // FIX 1: Initialize in case k=1 skips the loop
        if(dummy == nullptr){
            return nullptr;
        }
        for(int i=1; i<k ; i++){
            if(dummy->next){
            kptr = dummy->next;
            dummy=dummy->next;
            }
            else{
                kptr = nullptr;
                break;
            }
        };
        return kptr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1 || !head) return head; // Edge case safety

        ListNode* dummy = head;
        ListNode* prev = dummy;
        ListNode* kpointer = getK(dummy, k);
        
        if(kpointer==nullptr){
            return head;
        };
        
        nhead = kpointer;
        ListNode* curr = prev->next ? prev->next : nullptr;
        ListNode* nxt = curr ? curr->next : nullptr;

        while( kpointer && curr ){

            if(kpointer == curr){
                // FIX 2: Break the circle, connect parent, and reset boundary
                ListNode* nextK = getK(nxt, k);
                dummy->next = nextK ? nextK : nxt; // Connect parent to next group's head
                dummy = nxt;                       // Set up dummy for the next round
                kpointer = nextK;                  // Update kpointer
                
                curr->next = prev; // Complete the reversal for this group
                
                // Reset pointers for the next group so reversal doesn't bleed
                if (!nxt) break;
                prev = nxt;
                curr = nxt->next;
                nxt = curr ? curr->next : nullptr;
                continue; 
            }
            
            curr->next = prev;
            prev= curr;
            curr= nxt;
            nxt = nxt ? nxt->next : nullptr; // FIX 3: Prevent Segfault
        }
        
        return nhead;
    }
};