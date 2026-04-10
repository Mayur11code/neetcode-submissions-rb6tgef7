/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;

        Node* copy = head;
        while(copy){
            Node* node = new Node(copy->val);
            m[copy]= node;
            copy= copy->next;

        }

        Node* randcpy = head;
        while(randcpy){
            m[randcpy]->random = m[randcpy->random] ;
            m[randcpy]->next = m[randcpy->next] ;
            randcpy = randcpy->next;

        }
            return m[head];
    }
};
