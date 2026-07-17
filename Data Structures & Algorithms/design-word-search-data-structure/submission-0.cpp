class WordDictionary {
public:
    class Node{
        public:
        unordered_map<char,Node*> children;
        bool isAWord;
        Node() { isAWord = false; }

    };

    Node* curr = nullptr;
    Node* root = new Node();

    WordDictionary() {
        
    }

    bool backtrack(string& word, int index, Node* currnode){
        if(index < word.size()){
            if(word[index]!='.'){
                char c = word[index];
                if(currnode->children[c]==nullptr){
                    return false;
                }
                Node* curr = currnode->children[c];
                return backtrack(word,index+1,curr);
            }
            for(auto& [key,value]: currnode->children){
                if(value==nullptr){
                    continue;
                }
               bool val = backtrack(word,index+1,value);
               if(val){
                return val;
               }
            }
            return false;
        }
        if(index==word.size()){
            if(currnode->isAWord){
            return true;
            }
            return false;
        }
        return false;
        
    }
    
    void addWord(string word) {
        curr = root;
        for(auto& c : word){
            if(curr->children[c]==nullptr){
                Node* pt = new Node();
                curr->children[c] = pt;
                curr=pt;
                
            }
            else{
            curr = curr->children[c];
            }
        }
        curr->isAWord = true;
    }
    
    bool search(string word) {
        curr = root;
        return backtrack(word,0,curr);


    }
};
