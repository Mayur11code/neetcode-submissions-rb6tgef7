class PrefixTree {
public:

    class Node{
        public:
        unordered_map<char,Node*> children;
        bool isAWord;
        Node() { isAWord = false; }

    };


    Node* curr = nullptr;
    Node* root = new Node();

    PrefixTree() {

    }
    
    void insert(string word) {
        curr = root;
        for(auto& c : word){
            if(curr->children[c]==nullptr){
            Node* pt = new Node();
            curr->children[c] = pt;
            curr= pt;
            }
            else{
                curr = curr->children[c];
            }
        }
        curr->isAWord = true;
    }
    
    bool search(string word) {
        
        curr = root;
        for(auto& c : word){
            if(curr->children[c] == nullptr){
                return false;
            }
            curr= curr->children[c];

        }
        return curr->isAWord;

    }
    
    bool startsWith(string prefix) {
            curr = root;
        for(auto& c : prefix){
            if(curr->children[c] == nullptr){
                return false;
            }
            curr= curr->children[c];

        }
        return true;

    }
};
