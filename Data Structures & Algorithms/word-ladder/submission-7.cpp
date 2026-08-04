class Solution {
public:
    unordered_map<string,vector<string>> words;

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        

        for(auto& word : wordList){

            for(int i=0; i<word.size();i++){
                string key = word;
                key[i]='_';
                words[key].push_back(word);
            }

        }


        queue<string> main;
        unordered_set<string> visited;
        main.push(beginWord);
        int steps=0;
        bool found = false;
        while(!main.empty()){
            int limit = main.size();

            for(int j =0; j<limit; j++){
            string curr = main.front();
            main.pop();
            if(curr == endWord){
                found = true;
                return steps+1;
            }
            

            for(int i=0; i < curr.size(); i++){
                string key = curr;
                key[i]='_';

                vector<string> neighbor = words[key];

                if(neighbor.size()>0){
                for(auto& w : neighbor){
                    if(!visited.contains(w)){
                    main.push(w);
                    visited.insert(w);
                    }
                }
                }
            }
            }
            steps++;

        }

        return found ? steps : 0;
    }
};
