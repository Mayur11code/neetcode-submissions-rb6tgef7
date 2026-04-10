class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> m;

        Node* copy = head;
        while (copy) {
            Node* node = new Node(copy->val);
            m[copy] = node;
            copy = copy->next;
        }

        Node* randcpy = head;
        while (randcpy) {
            m[randcpy]->random = randcpy->random ? m[randcpy->random] : nullptr;
            m[randcpy]->next   = randcpy->next   ? m[randcpy->next]   : nullptr;
            randcpy = randcpy->next;
        }

        return m[head];
    }
};