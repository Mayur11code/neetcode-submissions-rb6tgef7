class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int cap;
    std::unordered_map<int, Node*> cache;
    Node* dummyHead;
    Node* dummyTail;

    void deleteNode(Node* delNode) {
        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;
        
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void addNode(Node* newNode) {
        Node* headNext = dummyHead->next;
        
        dummyHead->next = newNode;
        newNode->prev = dummyHead;
        newNode->next = headNext;
        headNext->prev = newNode;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        dummyHead = new Node(-1, -1);
        dummyTail = new Node(-1, -1);
        
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        
        Node* resNode = cache[key];
        
        deleteNode(resNode);
        addNode(resNode);
        
        return resNode->value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* existingNode = cache[key];
            existingNode->value = value; 
            
            deleteNode(existingNode);
            addNode(existingNode);
        } 
        else {
            Node* newNode = new Node(key, value);
            cache[key] = newNode; 
            addNode(newNode);     
            
            if (cache.size() > cap) {
                Node* lruNode = dummyTail->prev;
                
                cache.erase(lruNode->key);
                deleteNode(lruNode);
                delete lruNode; 
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */