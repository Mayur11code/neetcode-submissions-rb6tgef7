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
     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1==nullptr || list2==nullptr){
            if(list1==nullptr){
                return list2;
            }
            else return list1;
        }
        ListNode* head = list1->val <= list2->val ? list1 : list2 ;
        ListNode* curr = head;
        ListNode* n1 =(head == list1) ? list1->next : list1;
        ListNode* n2 = (head == list2) ? list2->next : list2;

        while(n1!=nullptr && n2!= nullptr){

            if(n1->val <= n2->val){
                curr->next = n1;
                curr=n1;
                n1=n1->next;
            }
            else{
                curr->next = n2;
                curr=n2;
                n2=n2->next;
            }

        }
        if(n1==nullptr){
            curr->next = n2;
        }
        else curr->next =n1;

        return head;
        
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if (lists.empty()) return nullptr;
    return divideAndConquer(lists, lists.size());
}

ListNode* divideAndConquer(vector<ListNode*>& lists, int k) {
    // 1. Base case: If k == 1, you have your final list. What do you return?
    if(k==1){
        return lists[0];
    }
    // 2. Setup your two pointers (left at 0, right at k - 1)
    int left = 0;
    int right = k-1;
    
    // 3. Loop: while left < right
        // - merge lists[left] and lists[right] using your helper
        // - store the result back into lists[left]
        // - move left++, right--

    while(left<right){
        lists[left] = mergeTwoLists(lists[left], lists[right]);
        left++;
        right--;
    }

    return divideAndConquer(lists, right+1 );
        
    // 4. Recursive call: pass 'lists' and your new boundary
}
        
};

