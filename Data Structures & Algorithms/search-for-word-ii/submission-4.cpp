class Solution {
public:

    class Node{
        public:
        bool isAWord;
        unordered_map<char,Node*> children;

        Node(){
            isAWord = false;
        }
    };
    
    class Trie{
        public:
            Node* root = new Node();
            Node* curr = nullptr;

            Trie(){

            };

            void addWord(string &word){

                curr = root;
                for(auto& c: word){
                    if(curr->children[c]==nullptr){
                        Node* child = new Node();
                        curr->children[c]= child;
                    }
                
                    curr = curr->children[c];

                }
                curr->isAWord = true;

            }

            void backtrack(Node* currnode, unordered_set<int> visited, int x, int y, vector<string>& result, string currstate, vector<vector<char>>& board) {

    if(currnode->isAWord){
        result.push_back(currstate);
        currnode->isAWord = false; // Prevent adding the exact same word instance multiple times
    }
    
    int right = x+1 < board.size() ? x+1 : -1;
    int left = x-1 > -1 ? x-1 : -1;
    int top = y-1 > -1 ? y-1 : -1;
    int bottom = y+1 < board[x].size() ? y+1 : -1;

    if(right != -1 && currnode->children[board[right][y]]!=nullptr){
        int hashed = Solution::hash(right,y);
        if(visited.find(hashed) == visited.end()) { // Verify not already visited
            visited.insert(hashed);
            currstate += board[right][y];
            
            backtrack(currnode->children[board[right][y]], visited, right, y, result, currstate, board);
            visited.erase(hashed);
            currstate.pop_back();
        }
    }
    if(left != -1 && currnode->children[board[left][y]]!=nullptr){
        int hashed = Solution::hash(left,y);
        if(visited.find(hashed) == visited.end()) {
            visited.insert(hashed);
            currstate += board[left][y];
            
            // FIX: Changed board[right][y] to board[left][y]
            backtrack(currnode->children[board[left][y]], visited, left, y, result, currstate, board);
            visited.erase(hashed);
            currstate.pop_back();
        }
    }
    if(top != -1 && currnode->children[board[x][top]]!=nullptr){
        int hashed = Solution::hash(x,top);
        if(visited.find(hashed) == visited.end()) {
            visited.insert(hashed);
            currstate += board[x][top];
            
            // FIX: Changed board[right][y] to board[x][top]
            backtrack(currnode->children[board[x][top]], visited, x, top, result, currstate, board);
            visited.erase(hashed);
            currstate.pop_back();
        }
    }
    if(bottom != -1 && currnode->children[board[x][bottom]]!=nullptr){
        int hashed = Solution::hash(x,bottom);
        if(visited.find(hashed) == visited.end()) {
            visited.insert(hashed);
            currstate += board[x][bottom];
            
            backtrack(currnode->children[board[x][bottom]], visited, x, bottom, result, currstate, board);
            visited.erase(hashed);
            currstate.pop_back();
        }
    }
}

    };

    static int hash(int y, int x){
        return y*(100)-x*(7);
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    
        Trie* trie = new Trie();
        for(auto& c : words){
            trie->addWord(c);
        }

        vector<string> result;


        for(int i =0 ; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){

                char c = board[i][j];
                if(trie->root->children[c]!=nullptr){

                int y = i;
                int x = j;

                unordered_set<int> visited;
                
                int hashed = hash(y,x);
                visited.insert(hashed);
                trie->backtrack(trie->root->children[c],visited,y,x,result,string(1, c),board);
                }
            }
        }


        return result;


    }
};
